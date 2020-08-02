#include <iostream>
#include<set>
#include<map>
using namespace std;


/*
3
Rahul Ajay 100
Ajay Neha 50
Neha Rahul 40
Output - Should also show transactions
Rahul pays 50 to Ajay
Rahul pays 10 to Neha
2
*/

int main(){

    int no_of_transactions;
    cin>>no_of_transactions;

    string x,y;
    int amount;

    map<string,int> net;

    while(no_of_transactions--){

        cin>>x>>y>>amount;


        net[x] -= amount;// net credit
        net[y] += amount;//and debit
    }


    multiset<pair<int,string>> m;

    for(auto p:net){
        string person = p.first;
        int amount = p.second;

        if(net[person]!=0){// if net is not zero of person
            m.insert({amount,person});
        }
    }

    //3. settlements (start & end)// to minimize do max Transaction first
    int cnt = 0;
    while(!m.empty()){
        auto low = m.begin();
        auto high = prev(m.end());

        int debit = low->first;
        string debit_person = low->second;

        int credit = high->first;
        string credit_person = high->second;


        m.erase(low);
        m.erase(high);

        int settled_amount = credit-abs(debit);
        if(settled_amount>0){
         credit = settled_amount;
         settled_amount=abs(debit);
         debit = 0;

        }
        else{


            debit = settled_amount;
            settled_amount =credit;
            credit = 0;
        }

     cout<<debit_person<<" will pay "<<settled_amount<<" to "<<credit_person<<endl;

        if(debit!=0){
            m.insert(make_pair(debit,debit_person));
        }
        if(credit!=0){
            m.insert(make_pair(credit,credit_person));
        }
        cnt += 1;

    }
    cout<<cnt<<endl;
return 0;
}
