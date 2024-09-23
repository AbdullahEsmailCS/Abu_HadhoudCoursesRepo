#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <ctime>

class FileNode {
public:
    std::string name;
    std::string type; // "file" or "directory"
    std::string content; // For files
    std::vector<FileNode*> children; // For directories
    size_t size; // File size
    time_t creationDate;
    time_t modificationDate;

    FileNode(const std::string& name, const std::string& type)
        : name(name), type(type), size(0) {
        creationDate = modificationDate = time(nullptr);
    }
};

class FileSystem {
private:
    FileNode* root; // Root directory
    std::unordered_map<std::string, FileNode*> fileMap; // Maps file names to nodes

    // Helper function to find a directory node based on the path
    FileNode* findDirectory(const std::string& path) {
        FileNode* current = root;
        if (path == "/") return current; // Root case
        size_t pos = 1; // Start after the '/'
        size_t nextPos;

        while ((nextPos = path.find('/', pos)) != std::string::npos) {
            std::string dirName = path.substr(pos, nextPos - pos);
            bool found = false;
            for (FileNode* child : current->children) {
                if (child->name == dirName && child->type == "directory") {
                    current = child;
                    found = true;
                    break;
                }
            }
            if (!found) return nullptr; // Directory not found
            pos = nextPos + 1; // Move to the next segment
        }

        return current; // Return the current directory
    }

public:
    FileSystem() {
        root = new FileNode("/", "directory"); // Create root directory
        fileMap["/"] = root; // Map root directory
    }

    void createFile(const std::string& path, const std::string& content) {
        size_t lastSlash = path.find_last_of('/');
        std::string dirPath = path.substr(0, lastSlash);
        std::string fileName = path.substr(lastSlash + 1);

        FileNode* parentDir = findDirectory(dirPath);
        if (!parentDir) {
            std::cout << "Error: Parent directory does not exist.\n";
            return;
        }

        for (FileNode* child : parentDir->children) {
            if (child->name == fileName && child->type == "file") {
                std::cout << "Error: File already exists.\n";
                return;
            }
        }

        FileNode* newFile = new FileNode(fileName, "file");
        newFile->content = content;
        newFile->size = content.size();
        parentDir->children.push_back(newFile);
        fileMap[path] = newFile; // Map the new file path
        std::cout << "File created: " << path << "\n";
    }

    void readFile(const std::string& path) {
        if (fileMap.find(path) == fileMap.end()) {
            std::cout << "Error: File does not exist.\n";
            return;
        }
        FileNode* file = fileMap[path];
        if (file->type == "file") {
            std::cout << "Content of " << path << ":\n" << file->content << "\n";
        }
        else {
            std::cout << "Error: Path is a directory, not a file.\n";
        }
    }

    void updateFile(const std::string& path, const std::string& content) {
        if (fileMap.find(path) == fileMap.end()) {
            std::cout << "Error: File does not exist.\n";
            return;
        }
        FileNode* file = fileMap[path];
        if (file->type == "file") {
            file->content = content;
            file->size = content.size();
            file->modificationDate = time(nullptr);
            std::cout << "File updated: " << path << "\n";
        }
        else {
            std::cout << "Error: Path is a directory, not a file.\n";
        }
    }

    void deleteFile(const std::string& path) {
        if (fileMap.find(path) == fileMap.end()) {
            std::cout << "Error: File does not exist.\n";
            return;
        }

        FileNode* file = fileMap[path];
        if (file->type == "file") {
            size_t lastSlash = path.find_last_of('/');
            std::string dirPath = path.substr(0, lastSlash);
            FileNode* parentDir = findDirectory(dirPath);
            parentDir->children.erase(std::remove(parentDir->children.begin(), parentDir->children.end(), file), parentDir->children.end());
            fileMap.erase(path); // Remove from map
            delete file; // Free memory
            std::cout << "File deleted: " << path << "\n";
        }
        else {
            std::cout << "Error: Path is a directory, not a file.\n";
        }
    }

    void createDirectory(const std::string& path) {
        if (fileMap.find(path) != fileMap.end()) {
            std::cout << "Error: Directory already exists.\n";
            return;
        }

        size_t lastSlash = path.find_last_of('/');
        std::string dirPath = path.substr(0, lastSlash);
        std::string dirName = path.substr(lastSlash + 1);

        FileNode* parentDir = findDirectory(dirPath);
        if (!parentDir) {
            std::cout << "Error: Parent directory does not exist.\n";
            return;
        }

        for (FileNode* child : parentDir->children) {
            if (child->name == dirName && child->type == "directory") {
                std::cout << "Error: Directory already exists.\n";
                return;
            }
        }

        FileNode* newDir = new FileNode(dirName, "directory");
        parentDir->children.push_back(newDir);
        fileMap[path] = newDir; // Map the new directory path
        std::cout << "Directory created: " << path << "\n";
    }

    void deleteDirectory(const std::string& path) {
        if (fileMap.find(path) == fileMap.end()) {
            std::cout << "Error: Directory does not exist.\n";
            return;
        }

        FileNode* dir = fileMap[path];
        if (dir->type == "directory") {
            if (!dir->children.empty()) {
                std::cout << "Error: Directory is not empty.\n";
                return;
            }

            size_t lastSlash = path.find_last_of('/');
            std::string parentDirPath = path.substr(0, lastSlash);
            FileNode* parentDir = findDirectory(parentDirPath);
            parentDir->children.erase(std::remove(parentDir->children.begin(), parentDir->children.end(), dir), parentDir->children.end());
            fileMap.erase(path); // Remove from map
            delete dir; // Free memory
            std::cout << "Directory deleted: " << path << "\n";
        }
        else {
            std::cout << "Error: Path is a file, not a directory.\n";
        }
    }

    ~FileSystem() {
        // Implement a destructor to free allocated memory
        delete root;
    }
};

int main() {
    FileSystem fs;

    fs.createDirectory("/documents");
    fs.createFile("/documents/file1.txt", "Hello, World!");
    fs.readFile("/documents/file1.txt");
    fs.updateFile("/documents/file1.txt", "Updated Content!");
    fs.readFile("/documents/file1.txt");
    fs.deleteFile("/documents/file1.txt");
    fs.deleteDirectory("/documents");

    return 0;
}
