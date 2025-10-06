#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <sstream>
#include <algorithm>

using namespace std;

struct Literal {
    string name;
    bool negated;
    
    Literal(string n = "", bool neg = false) : name(n), negated(neg) {}
    
    bool isComplement(const Literal& other) const {
        return name == other.name && negated != other.negated;
    }
    
    bool operator<(const Literal& other) const {
        if (name != other.name) return name < other.name;
        return negated < other.negated;
    }
    
    bool operator==(const Literal& other) const {
        return name == other.name && negated == other.negated;
    }
};

typedef set<Literal> Clause;

class Resolution {
private:
    // 改进的解析函数
    void parseCNF(const string& formula) {
        clauses.clear();
        string processed = formula;
        
        // 移除空格
        processed.erase(remove(processed.begin(), processed.end(), ' '), processed.end());
        
        size_t start = 0;
        size_t end = 0;
        
        while (start < processed.length()) {
            // 找到下一个合取符号或字符串结束
            end = processed.find('&', start);
            if (end == string::npos) {
                end = processed.length();
            }
            
            // 提取子句
            string clauseStr = processed.substr(start, end - start);
            Clause clause = parseClause(clauseStr);
            
            if (!clause.empty()) {
                clauses.push_back(clause);
            }
            
            start = end + 1;
        }
    }
    
    // 解析单个子句
    Clause parseClause(const string& clauseStr) {
        Clause clause;
        string currentVar;
        bool negated = false;
        
        for (char c : clauseStr) {
            if (c == '!') {
                negated = true;
            } else if (c == '|' || c == '(' || c == ')') {
                // 忽略这些符号
                continue;
            } else if (c >= 'a' && c <= 'z') {
                // 命题变元
                currentVar = string(1, c);
                clause.insert(Literal(currentVar, negated));
                negated = false; // 重置否定状态
            }
        }
        
        return clause;
    }
    
    bool isTautology(const Clause& clause) {
        for (const auto& lit1 : clause) {
            Literal complement(lit1.name, !lit1.negated);
            if (clause.find(complement) != clause.end()) {
                return true;
            }
        }
        return false;
    }
    
    vector<Clause> resolve(const Clause& c1, const Clause& c2) {
        vector<Clause> resolvents;
        
        for (const auto& lit1 : c1) {
            Literal complement(lit1.name, !lit1.negated);
            if (c2.find(complement) != c2.end()) {
                // 找到互补文字
                Clause resolvent;
                
                // 添加c1中除lit1外的所有文字
                for (const auto& l : c1) {
                    if (!(l == lit1)) {
                        resolvent.insert(l);
                    }
                }
                
                // 添加c2中除complement外的所有文字
                for (const auto& l : c2) {
                    if (!(l == complement)) {
                        resolvent.insert(l);
                    }
                }
                
                if (!isTautology(resolvent)) {
                    resolvents.push_back(resolvent);
                }
            }
        }
        
        return resolvents;
    }

public:
    vector<Clause> clauses;
    
    bool isSatisfiable(const string& formula) {
        parseCNF(formula);
        
        vector<Clause> S;
        // 移除永真子句
        for (const auto& clause : clauses) {
            if (!isTautology(clause)) {
                S.push_back(clause);
            }
        }
        
        // 如果初始子句集为空，则可满足
        if (S.empty()) return true;
        
        // 检查是否包含空子句
        for (const auto& clause : S) {
            if (clause.empty()) return false;
        }
        
        while (true) {
            vector<Clause> newClauses;
            
            // 生成所有可能的消解式
            for (int i = 0; i < S.size(); i++) {
                for (int j = i + 1; j < S.size(); j++) {
                    vector<Clause> resolvents = resolve(S[i], S[j]);
                    
                    for (const auto& resolvent : resolvents) {
                        // 空子句意味着不可满足
                        if (resolvent.empty()) {
                            return false;
                        }
                        
                        // 检查是否是新子句
                        bool exists = false;
                        for (const auto& c : S) {
                            if (c == resolvent) {
                                exists = true;
                                break;
                            }
                        }
                        for (const auto& c : newClauses) {
                            if (c == resolvent) {
                                exists = true;
                                break;
                            }
                        }
                        
                        if (!exists) {
                            newClauses.push_back(resolvent);
                        }
                    }
                }
            }
            
            // 没有新子句产生，则可满足
            if (newClauses.empty()) {
                return true;
            }
            
            // 添加新子句
            for (const auto& newClause : newClauses) {
                S.push_back(newClause);
            }
            
            // 防止无限循环
            if (S.size() > 1000) {
                return true;
            }
        }
    }
};

int main() {
    string input;
    getline(cin, input);
    
    if (!input.empty() && input.back() == '\r') {
        input.pop_back();
    }
    
    Resolution resolver;
    if (resolver.isSatisfiable(input)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}