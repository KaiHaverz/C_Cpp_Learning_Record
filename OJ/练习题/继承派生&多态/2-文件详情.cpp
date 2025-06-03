#include <iostream>
#include <string>
#include <cctype>
using namespace std;

const string ENCODINGS[4] = {"ASCII", "Unicode", "UTF8", "ANSI"};

// 基类：文件
class File {
protected:
    string filename;
    long filesize;
public:
    File(const string& name, long size) : filename(name), filesize(size) {}
    virtual ~File() {}
};

// 派生类：文本文件
class TextFile : public File {
private:
    int fileEncoder;  // 0: ASCII, 1: Unicode, 2: UTF8, 3: ANSI
    
    // 编码转换函数
    string encodingToString() const {
        return ENCODINGS[fileEncoder];
    }
    
public:
    // 构造函数
    TextFile(const string& name, long size, int encoder) 
        : File(name, size), fileEncoder(encoder) {}
    
    // 更新文件大小
    void UpdateFilesize(long size) {
        filesize = size;
    }
    
    // 仅更新编码方式 (整型版本)
    void UpdateFile(int encodeFlag) {
        fileEncoder = encodeFlag;
    }
    
    // 仅更新编码方式 (字符串版本)
    void UpdateFile(const string& encode) {
        for (int i = 0; i < 4; i++) {
            if (ENCODINGS[i] == encode) {
                fileEncoder = i;
                return;
            }
        }
    }
    
    // 更新编码和文件名 (整型版本)
    void UpdateFile(int encodeFlag, const string& name) {
        fileEncoder = encodeFlag;
        filename = name;
    }
    
    // 更新编码和文件名 (字符串版本)
    void UpdateFile(const string& encode, const string& name) {
        UpdateFile(encode);
        filename = name;
    }
    
    // 显示文件信息
    void Show() const {
        cout << filename << " " << filesize << " " << encodingToString() << endl;
    }
};

int main() {
    // 读取初始数据
    string name;
    long size;
    int encoder;
    cin >> name >> size >> encoder;
    
    // 创建文本文件对象
    TextFile file(name, size, encoder);
    
    // 读取操作数量
    int n;
    cin >> n;
    
    // 处理操作
    while (n--) {
        char op;
        cin >> op;
        
        switch (op) {
            case 'S': 
                file.Show();
                break;
            case 's': {
                long newSize;
                cin >> newSize;
                file.UpdateFilesize(newSize);
                break;
            }
            case 'E': {
                int newEncoder;
                cin >> newEncoder;
                file.UpdateFile(newEncoder);
                break;
            }
            case 'e': {
                int newEncoder;
                string newName;
                cin >> newEncoder;
                // 读取整个行包括空格
                if (cin.peek() == ' ') cin.ignore(); // 忽略空格
                getline(cin, newName);
                file.UpdateFile(newEncoder, newName);
                break;
            }
            default:
                cout << "No such function!" << endl;
                // 清除当前行的剩余输入
                cin.ignore(1000, '\n');
                break;
        }
    }
    
    return 0;
}