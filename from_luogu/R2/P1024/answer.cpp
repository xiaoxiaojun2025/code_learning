#include<iostream>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<cmath>
using namespace std;

int calculate(vector<double> v, double x){
    double res = x*x*x*v[0] + x*x*v[1] + x*v[2] + v[3];
    if(fabs(res) < 1e-4) return 0;  // 使用精度判断
    else if(res > 0) return 1;
    else return -1;
}

void getAnswer(vector<double> v, double left, double right, vector<double> &res){
    if(res.size() >= 3) return;
    if(left > 100) return;  // 超出范围停止
    
    int lflag = calculate(v, left);
    int rflag = calculate(v, right);

    // 检查左端点是否为根
    if(lflag == 0) {
        res.push_back(left);
        // 跳过当前区间，检查下一个区间
        if(left < 100) getAnswer(v, left + 1, left + 2, res);
        return;
    }

    // 检查区间内是否有根
    if(lflag * rflag <= 0){
        if(right - left < 0.0001){
            res.push_back((left + right) / 2);
            // 继续检查下一个区间
            if(right < 100) getAnswer(v, right + 1, right + 2, res);
            return;
        }
        
        double mid = (left + right) / 2;
        int mflag = calculate(v, mid);
        
        if(mflag == 0){
            res.push_back(mid);
            if(right < 100) getAnswer(v, right + 1, right + 2, res);
        }
        else{
            if(mflag != lflag) 
                getAnswer(v, left, mid, res);
            else 
                getAnswer(v, mid, right, res);
        }
    } 
    else {
        // 当前区间无根，检查下一个区间
        if(right < 100) getAnswer(v, right, right + 1, res);
    }
}

int main(){
    double a, b, c, d;
    cin >> a >> b >> c >> d;
    vector<double> res;
    
    // 从-100开始正确遍历
    getAnswer({a, b, c, d}, -100, -99, res);
    
    // 确保输出三个根（题目保证有三个实根）
    for(int i = 0; i < 3; i++){
        cout << fixed << setprecision(2) << res[i] << " ";
    }
    return 0;
}