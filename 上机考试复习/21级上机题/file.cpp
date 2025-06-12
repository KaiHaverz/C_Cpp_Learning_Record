#include<iostream>
#include<string>
using namespace std;

class File{
protected:
    string filename;
    int filesize;

public:
    File(string s,int f):filename(s),filesize(f) {}

    virtual void UpdateFile(string newName,int newSize,int newFileEncoder)=0;
    virtual void Show()=0;
};


class ChangeEncode_name : public File{
protected:
    int  fileEncoder;

public:
    ChangeEncode_name(string s,int f,int fe):File(s,f),fileEncoder(fe) {}

    void UpdateFile(string newName,int newSize,int newFileEncoder) override{
        filename=newName;
        fileEncoder=newFileEncoder;
    }

    void Show() override{
        string encode;
        switch(fileEncoder){
            case(0): encode="ASCII"; break;
            case(1): encode="UNICODE"; break;
            case(2): encode="UTF8"; break;
            case(3): encode="ANSI"; break;
            default: encode="UNKNOWN";
        }

        cout<<"change_encodeAndname:"<<filename<<" "<<filesize<<" "<<encode<<endl;
    }
};


class ChangeEncode_size : public File{
protected:
    int  fileEncoder;

public:
    ChangeEncode_size(string s,int f,int fe):File(s,f),fileEncoder(fe) {}

    void UpdateFile(string newName,int newSize,int newFileEncoder) override{
        filename=newName;
        filesize=newSize;
    }

    void Show() override{
        string encode;
        switch(fileEncoder){
            case(0): encode="ASCII"; break;
            case(1): encode="UNICODE"; break;
            case(2): encode="UTF8"; break;
            case(3): encode="ANSI"; break;
            default: encode="UNKNOWN";
        }

        cout<<"change_encodeAndsize:"<<filename<<" "<<filesize<<" "<<encode<<endl;
    }
};


int main(){
    string name;
    int size;
    int kind;
    cin>>name>>size>>kind;

    char operation;
    cin>>operation;

    File *file=NULL;

    if(operation=='N'){
        string newName;
        int newKind;
        cin>>newName>>newKind;

        file=new ChangeEncode_name(name,size,kind);
        file->UpdateFile(newName,0,newKind);
        file->Show();
    }
    else if(operation=='S'){
        int newSize;
        int newKind;
        cin>>newSize>>newKind;

        file=new ChangeEncode_size(name,size,kind);
        file->UpdateFile("0",newSize,newKind);
        file->Show(); 
    }
    else{
        cout<<"No such operation!"<<endl;
        return 0;
    }

    return 0;
}