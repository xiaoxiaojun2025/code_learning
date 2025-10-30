#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

// 广义表节点类型
enum NodeType { ATOM, LIST };

// 广义表节点结构
struct GListNode {
    NodeType tag; // 节点类型：ATOM-原子，LIST-子表
    union {
        char atom; // 原子值
        struct {
            GListNode* hp; // 表头指针
            GListNode* tp; // 表尾指针
        } ptr;
    };
    
    GListNode(NodeType t, char a = '\0') : tag(t) {
        if (t == ATOM) atom = a;
        else {
            ptr.hp = nullptr;
            ptr.tp = nullptr;
        }
    }
};

typedef GListNode* GList;

// 函数声明
bool CreateGList(GList& L, char* S);
GList GetHead(GList L);
GList GetTail(GList L);
void DestroyGList(GList& L);
void PrintGList(GList L);
GList CreateSubList(char*& s);
void SkipSpace(char*& s);


// 根据字符串S建立广义表
bool CreateGList(GList& L, char* S) {
    if (S == nullptr || strlen(S) == 0) {
        L = nullptr;
        return true;
    }
    
    char* s = S;
    L = CreateSubList(s);
    return L != nullptr;
}

// 递归创建子表
GList CreateSubList(char*& s) {
    SkipSpace(s);
    if (*s == '\0') return nullptr;
    
    if (*s == '(') {
        // 创建表节点
        s++; // 跳过'('
        SkipSpace(s);
        
        // 空表情况
        if (*s == ')') {
            s++; // 跳过')'
            return nullptr;
        }
        
        GList node = new GListNode(LIST);
        GList current = node;
        
        while (*s != '\0' && *s != ')') {
            SkipSpace(s);
            
            // 创建表头
            current->ptr.hp = CreateSubList(s);
            SkipSpace(s);
            
            // 如果有逗号，继续处理表尾
            if (*s == ',') {
                s++; // 跳过','
                current->ptr.tp = new GListNode(LIST);
                current = current->ptr.tp;
            } else {
                break;
            }
        }
        
        if (*s == ')') s++; // 跳过')'
        return node;
    }
    else if ((*s >= 'a' && *s <= 'z') || (*s >= 'A' && *s <= 'Z')) {
        // 创建原子节点
        GList node = new GListNode(ATOM, *s);
        s++; // 跳过原子字符
        return node;
    }
    
    return nullptr;
}

// 跳过空格
void SkipSpace(char*& s) {
    while (*s == ' ') s++;
}

// 取表头运算
GList GetHead(GList L) {
    if (L == nullptr || L->tag == ATOM) {
        return nullptr;
    }
    return L->ptr.hp;
}

// 取表尾运算  
GList GetTail(GList L) {
    if (L == nullptr || L->tag == ATOM) {
        return nullptr;
    }
    return L->ptr.tp;
}

// 销毁广义表
void DestroyGList(GList& L) {
    if (L == nullptr) return;
    
    if (L->tag == LIST) {
        // 递归销毁表头和表尾
        DestroyGList(L->ptr.hp);
        DestroyGList(L->ptr.tp);
    }
    delete L;
    L = nullptr;
}

// 显示广义表内容
void PrintGList(GList L) {
    if (L == nullptr) {
        cout << "()";
        return;
    }
    
    if (L->tag == ATOM) {
        cout << L->atom;
        return;
    }
    
    cout << "(";
    GList current = L;
    bool first = true;
    
    while (current != nullptr) {
        if (!first) cout << ",";
        first = false;
        
        PrintGList(current->ptr.hp);
        current = current->ptr.tp;
    }
    cout << ")";
}

// 主函数
int main() {
    char input[1000];
    cin.getline(input, 1000);
    
    GList L = nullptr;
    if (!CreateGList(L, input)) {
        cout << "创建广义表失败!" << endl;
        return 1;
    }
    
    cout << "generic list: ";
    PrintGList(L);
    cout << endl;
    
    int command;
    while (true) {
        // 检查是否为空表或原子
        if (L == nullptr) {
            cout << "generic list: ()" << endl;
            break;
        }
        if (L->tag == ATOM) {
            // 移到这里输出，避免重复输出
            // cout << "generic list: ";
            // PrintGList(L);
            // cout << endl;
            break;
        }
        
        cin >> command;
        
        if (command == 1) {
            // 取表头
            GList oldL = L;
            GList head = GetHead(L);
            
            cout << "destroy tail" << endl;
            if (L->ptr.tp != nullptr) {
                DestroyGList(L->ptr.tp);
            }
            cout << "free list node" << endl;
            
            L->ptr.tp = nullptr;
            L = head;
            delete oldL;
            
            cout << "generic list: ";
            PrintGList(L);
            cout << endl;
            
            // 输出后立即检查是否应该退出
            if (L == nullptr || L->tag == ATOM) {
                break;
            }
        }
        else if (command == 2) {
            // 取表尾
            GList oldL = L;
            GList tail = GetTail(L);
            
            cout << "free head node" << endl;
            if (L->ptr.hp != nullptr) {
                DestroyGList(L->ptr.hp);
            }
            
            L->ptr.hp = nullptr;
            L = tail;
            delete oldL;
            cout << "free list node" << endl;
            
            cout << "generic list: ";
            PrintGList(L);
            cout << endl;
            
            // 输出后立即检查是否应该退出
            if (L == nullptr || L->tag == ATOM) {
                break;
            }
        }
        else {
            break;
        }
    }
    
    // 最终清理
    DestroyGList(L);
    return 0;
}
