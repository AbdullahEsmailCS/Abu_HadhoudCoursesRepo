#include<iostream>
#include<string>

using namespace std;

const int AcceptableFactor = 50;

enum class enResultStatus {
    Pass,
    Fail
};

bool IsGreater(int first, int second) {
    return first >= second;
}

bool CheckMarkCondition(int mark) {
    return IsGreater(mark, AcceptableFactor);
}

int ReadMark(const string& message) {
    cout << message << endl;
    int mark;
    cin >> mark;
    return mark;
}

enResultStatus CheckMark(int mark) {

    if (CheckMarkCondition(mark))
        return enResultStatus::Pass;
    else
        return enResultStatus::Fail;

}

string GetMarkStatusAsString(enResultStatus s) {
   
    switch (s)
    {
    case enResultStatus::Pass:
        return " Pass ";
        break;
    case enResultStatus::Fail:
        return " Fail ";
        break;
    default:
        return " ";
        break;
    }
}

void PrintResult(const string& state) {
    cout << state << endl;
}



int main() {

    PrintResult(GetMarkStatusAsString(CheckMark(ReadMark("Enter mark "))));

	return 0;
}