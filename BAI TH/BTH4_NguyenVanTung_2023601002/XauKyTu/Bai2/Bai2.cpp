#include <iostream>
#include <string>
using namespace std;

int main() {
    string text =
        "The child is smart. Every child should learn. A child can grow.";

    cout << "Van ban:\n" << text << endl;

    int count = 0;
    for (int i = 0; i + 4 < text.length(); i++) {
        if (text.substr(i, 5) == "child")
            count++;
    }

    cout << "So tu 'child': " << count << endl;

    // Thay thế
    int pos = 0;
    while ((pos = text.find("child", pos)) != string::npos) {
        text.replace(pos, 5, "children");
        pos += 8;
    }

    cout << "Van ban sau khi thay the:\n" << text << endl;
}
