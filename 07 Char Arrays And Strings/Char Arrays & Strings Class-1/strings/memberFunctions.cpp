#include<iostream>
using namespace std;
//member functions
int main(){
    string name = "Maharana Pratap";
    cout<<name[0]<<endl;  //M
    //at
    cout<<name.at(9)<<endl; //P
    //front
    cout<<name.front()<<endl; //M
    //back
    cout<<name.back()<<endl; //p
    //length
    cout<<name.length()<<endl; //15
    auto it = name.begin(); 
    while(it!=name.end()){
        cout<<*it<<" ";
        it++;                  // M a h a r a n a   P r a t a p 
    }
    cout<<endl;

    //substr
    cout<<name.substr(3,5)<<endl;  //arana
    cout<<name.substr(7)<<endl;   //a Pratap

    //find
    string word="Pra";
    int findd = name.find(word); //return index at which string is found
    cout<<findd<<endl;
    if(name.find(word)!= string::npos){ //npos represent no position found
        //found
    }
    else{
        //not found
    }

    //clear
    name.clear();
    //empty
    if(name.empty()){
        cout<<"string is empty"<<endl;
    }
    else{
        cout<<"string is not empty"<<endl;
    }

    //concat
    string fName = "Saumya";
    string lName = "Yadav";
    string ans = fName+" "+lName;
    cout<<ans<<endl;

    cout<<fName.compare(lName)<<endl; //ans is zero if both strings are same
    return 0;
}
