/*
* @Author: chenkexing
* @Date:   2018-10-10 06:48:22
* @Last Modified by:   chenkexing
* @Last Modified time: 2018-10-27 21:05:14
*   这是附加链表做学生管理系统的附加题目。
*/
//#pragma GCC optimize(3)
//#pragma comment(linker, "/STACK:102400000,102400000")  //c++
// #pragma GCC diagnostic error "-std=c++11"
// #pragma comment(linker, "/stack:200000000")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
// #pragma GCC optimize("-fdelete-null-pointer-checks,inline-functions-called-once,-funsafe-loop-optimizations,-fexpensive-optimizations,-foptimize-sibling-calls,-ftree-switch-conversion,-finline-small-functions,inline-small-functions,-frerun-cse-after-loop,-fhoist-adjacent-loads,-findirect-inlining,-freorder-functions,no-stack-protector,-fpartial-inlining,-fsched-interblock,-fcse-follow-jumps,-fcse-skip-blocks,-falign-functions,-fstrict-overflow,-fstrict-aliasing,-fschedule-insns2,-ftree-tail-merge,inline-functions,-fschedule-insns,-freorder-blocks,-fwhole-program,-funroll-loops,-fthread-jumps,-fcrossjumping,-fcaller-saves,-fdevirtualize,-falign-labels,-falign-loops,-falign-jumps,unroll-loops,-fsched-spec,-ffast-math,Ofast,inline,-fgcse,-fgcse-lm,-fipa-sra,-ftree-pre,-ftree-vrp,-fpeephole2",3)

#include <algorithm>
#include  <iterator>
#include  <iostream>
#include   <cstring>
#include   <cstdlib>
#include   <iomanip>
#include    <bitset>
#include    <cctype>
#include    <cstdio>
#include    <string>
#include    <vector>
#include     <stack>
#include     <cmath>
#include     <queue>
#include      <list>
#include       <map>
#include       <set>
#include   <cassert>

using namespace std;
#define lson (l , mid , rt << 1)
#define rson (mid + 1 , r , rt << 1 | 1)
#define debug(x) cerr << #x << " = " << x << "\n";
#define pb push_back
#define pq priority_queue



typedef long long ll;
typedef unsigned long long ull;
//typedef __int128 bll;
typedef pair<ll ,ll > pll;
typedef pair<int ,int > pii;
typedef pair<int,pii> p3;

//priority_queue<int> q;//这是一个大根堆q
//priority_queue<int,vector<int>,greater<int> >q;//这是一个小根堆q
#define fi first
#define se second
//#define endl '\n'

#define OKC ios::sync_with_stdio(false);cin.tie(0)
#define FT(A,B,C) for(int A=B;A <= C;++A)  //用来压行
#define REP(i , j , k)  for(int i = j ; i <  k ; ++i)
#define max3(a,b,c) max(max(a,b), c);
//priority_queue<int ,vector<int>, greater<int> >que;

const ll mos = 0x7FFFFFFF;  //2147483647
const ll nmos = 0x80000000;  //-2147483648
const int inf = 0x3f3f3f3f;
const ll inff = 0x3f3f3f3f3f3f3f3f; //18
const int mod = 1000000007;
const double esp = 1e-8;
const double PI=acos(-1.0);
const double PHI=0.61803399;    //黄金分割点
const double tPHI=0.38196601;


template<typename T>
inline T read(T&x){
    x=0;int f=0;char ch=getchar();
    while (ch<'0'||ch>'9') f|=(ch=='-'),ch=getchar();
    while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x=f?-x:x;
}


/*-----------------------showtime----------------------*/

        class Student{      //学生基本信息
            // private:
                
            public:
                string num,name,tel;
                int xb;     //性别，男为1，女为0;
                int age;

                Student(string num, string name,string tel,int xb,int age):num(num),name(name),tel(tel),xb(xb),age(age){}
                void change(string num0, string name0,string tel0,int xb0,int age0){
                    num = num0;
                    name = name0;
                    tel = tel0;
                    xb = xb0;
                    age = age0;
                }
                void show_base_info(){
                    cout<<num<<" "<<name<<" "<<tel<<" ";
                    if(xb == 1) cout<<"boy ";
                    else cout<<"girl ";
                    cout<<age<<endl;
                }
        };

        class Course{            
            // private:
            public:
                string course_name;
                int course_soccer;
                Course * next;
                Course(string name,int soccer):course_name(name), course_soccer(soccer){}
        };
        class lnode{
            // private:
            public:
                Student stu;
                lnode * next;
                Course *CourseHead;

                lnode(string num,string name,string tel,int xb,int age):stu(num, name, tel, xb, age){
                    CourseHead = new Course("0", 0);
                    CourseHead->next = NULL;
                }

                void show_base_info(){
                    stu.show_base_info();
                }
                void show_course_info(){
                    Course *p = CourseHead->next;
                    if(p==NULL){
                        cout<<"该学生成绩暂无记录"<<endl;
                    }
                    while(p != NULL){
                        cout<<"\t"<<p -> course_name<<":="<<p->course_soccer<<endl;
                        p = p->next;
                    }
                }
                void change(string num,string name,string tel,int xb, int age){
                    stu.change(num, name, tel, xb, age);
                    cout<<"修改成功"<<endl;
                }
        };
        lnode *head;

        lnode *ClassHead[100];   //班级头指针

        void add_student(int x,string num,string name,string tel,int xb,int age){
            lnode *q = new lnode(num,name,tel,xb,age);
            lnode *p = ClassHead[x];
            while(p->next != NULL)p = p->next;
            p->next = q;
            q->next = NULL;
            cout<<"插入成功"<<endl;
        }
        void del(int x){
            lnode *p = ClassHead[x]->next,*q;

            while(p != NULL){
                q = p->next;
                delete(p);
                p = q;
            }

            ClassHead[x]->next = NULL;
            cout<<"清理成功"<<endl;
        }
        void del_stu(int x,string num){
            lnode *p = ClassHead[x]->next,*q,*w;
            int flag = 0;
            while(p->next != NULL && flag == 0){
                q = p->next;
                if((q->stu).num == num){
                    flag = 1;
                    w = q->next;
                    delete(q);
                    p->next = w;
                }
                p = p->next;
            }
            if(flag == 1) cout<<"删除成功"<<endl;
            else cout<<"未找到该同学"<<endl;
        }
        void add_course(int x,lnode *H ,string course_name,int soccer){
            Course *q = new Course(course_name, soccer);
            Course *p = H->CourseHead;
            while(p->next != NULL)p = p->next;
            p->next = q;
            q->next = NULL;
            cout<<"插入成功"<<endl;
        }

int main(){
        cout<<"请输入班级总数"<<endl;
        int cnt; cin>>cnt;          //cnt 保存班级的个数
        for(int i=1; i<=cnt; i++) ClassHead[i] = new lnode("0", "head", "0", 0, 0), ClassHead[i]->next = NULL;
        cout<<"----------功能一览----------"<<endl;
        cout<<"1:插入学生信息"<<endl;
        cout<<"2:修改班每个同学的基本情况"<<endl;
        cout<<"3:删除某班全部学生的信息"<<endl;
        cout<<"4:删除某班某个学生的信息"<<endl;
        cout<<"5:登记各班所有学生的各门成绩"<<endl;
        cout<<"6:修改某个学生某门功课的成绩"<<endl;
        cout<<"7:打印班级信息"<<endl;
        cout<<"8:打印每个学生的基本信息"<<endl;
        cout<<"9:打印每个学生的成绩信息"<<endl;
        cout<<"---------------------------"<<endl;
        while(true){
            int op; cin>>op;
            if(op == 1){
                cout<<"请输入学生的班级号"<<endl;
                int x;  cin>>x;
                cout<<"请输入学生的学号，姓名，电话，性别，年龄"<<endl;
                cout<<"其中男生性别 = 1， 女生性别 = 0"<<endl;
                string num,name,tel;
                int xb,age;
                cin>>num>>name>>tel>>xb>>age;
                add_student(x,num,name,tel,xb,age);
            }
            else if(op == 2){//修改班每个同学的基本情况
                cout<<"请输入要修改基本情况的班级号码"<<endl;
                int x;  cin>>x;
                lnode *p = ClassHead[x]->next;
                while(p != NULL){
                    cout<<"这个学生原信息为"<<endl;
                    p->show_base_info();
                    cout<<"请输入修改后这个学生的学号，姓名，电话，性别，年龄"<<endl;
                    cout<<"其中男生性别 = 1， 女生性别 = 0"<<endl;
                    string num,name,tel;
                    int xb,age;
                    // cout<<((p->next) == NULL)<<endl;
                    cin>>num>>name>>tel>>xb>>age;
                    p->change(num, name, tel, xb, age);
                    // cout<<((p->next) == NULL)<<endl;
                    p = p->next;
                    // break;
                }
            }    
            else if(op == 3){
                cout<<"请输入要修改基本情况的班级号码"<<endl;
                int x;  cin>>x;
                del(x);
            }      
            else if(op == 4){
                cout<<"请输入那个学生所在班级"<<endl;
                int x;  cin>>x;
                cout<<"请输入那个学生的学号"<<endl;
                string num; cin>>num;
                del_stu(x,num);
            } 
            else if(op == 5){
                cout<<"开始登记"<<endl;
                for(int i=1; i<=cnt; i++){
                    lnode *p = ClassHead[i]->next;
                    if(p != NULL)
                        cout<<"现在登记班级("<<i<<")的学生成绩"<<endl;

                    while(p != NULL){
                        cout<<"请输入学号为"<<(p->stu).num <<"的学生成绩个数"<<endl;
                        int c; cin>>c;
                        cout<<"请输入课程名称 + 成绩"<<endl;
                        while(c--){
                            string course_name;
                            int soccer;
                            cin>>course_name>>soccer;
                            add_course(i,p,course_name, soccer);
                        }
                        p=p->next;
                    }
                }
                cout<<"登记完成"<<endl;
            }
            else if(op == 6){
                cout<<"请输入该学生所在的班级和这个学生的学号"<<endl;
                int x;  string num;
                cin>>x>>num;
                lnode *p = ClassHead[x] -> next;
                while(p != NULL && (p->stu).num != num)p = p->next;  
                if(p == NULL) {
                    cout<<"查找不到此人"<<endl;
                }
                else {
                    cout<<"请输入要修改的课程名称和分数"<<endl;
                    string name;    int sc;
                    cin>>name>>sc;
                    Course *q = p->CourseHead->next;
                    while(q!=NULL){
                        if(q->course_name == name){
                            q->course_soccer = sc;
                            break;
                        }
                        q = q->next;
                    }
                    if(q == NULL) cout<<"未查到此人有这门课的成绩"<<endl;
                    else cout<<"修改成功"<<endl;
                }
            }
            else if(op == 7){
                for(int i=1; i<=cnt; i++){
                    cout<<"(" <<i<<") 班的基本信息"<<endl;
                    lnode *p = ClassHead[i] -> next;
                    while(p != NULL){
                        p->show_base_info();
                        p->show_course_info();
                        p = p->next;
                    }

                }
            }
            else if(op == 8){
                for(int i=1; i<=cnt; i++){
                    lnode *p = ClassHead[i] -> next;
                    while(p != NULL){
                        cout<<"(" <<i<<") 班 ";
                        p->show_base_info();
                        // p->show_course_info();
                        p = p->next;
                    }
                }
            }
            else {
                for(int i=1; i<=cnt; i++){
                    lnode *p = ClassHead[i] -> next;
                    while(p != NULL){
                        cout<<"(" <<i<<") 班 "<<(p->stu).num << " "<<(p->stu).name<<" :"<<endl;
                        // p->show_base_info();
                        p->show_course_info();
                        p = p->next;
                    }
                }
            }
        }
        return 0;
}
