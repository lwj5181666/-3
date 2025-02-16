#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> str(n);
    vector<string> num(n);
    for (int i = 0; i < n; i++) {
        cin >> str[i] >> num[i];
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    for (int i = 0; i < m; i++) {
        string s;
        getline(cin, s);
        size_t current_pos = 0;
        while (true) {
            size_t start = s.find("{", current_pos);
            size_t end = s.find("}", current_pos);
            
            // 检查是否找到匹配的 {} 对，并且顺序正确
            if (start == string::npos || end == string::npos || end <= start) {
                break; // 没有更多匹配项
            }
            
            string sub = s.substr(start + 1, end - start - 1);
            int target = -1;
            for (int j = 0; j < n; j++) {
                if (sub == str[j]) {
                    target = j;
                    break;
                }
            }
            
            if (target == -1) {
                current_pos = end + 1; // 继续查找下一对
                continue;
            }
            
            // 替换整个 {} 包括括号
            s.replace(start, end - start + 1, num[target]);
            
            // 更新当前位置，避免重复处理已替换部分
            current_pos = start + num[target].length();
        }
        cout << s << endl;
    }
    
    return 0;
}