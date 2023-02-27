#include<iostream>
/*
Sort books via insertion sort
Create a class book with title, author name, access number, price. Modify the insertion sort in the template code to

(i) Sort books in ascending order as per access number

(ii) Use vector

(iii) do minimal changes to the given code

*/

#include<vector>
using namespace std;
class book{
    public:
    string title,author_name;
    int access_no;
    float price;
};
int main(){
    int i,j,n;
    book key;
    vector<book> elements;
    //cout<<"Enter number of elements";
    cin>>n;
    for(i=0;i<n;i++){
        cin>>key.title;
        cin>>key.author_name;
        cin>>key.access_no;
        cin>>key.price;
        elements.push_back(key);
    }
    for(j=1;j<n;j++){
        key = elements[j];
        i = j-1;
        while((i>=0)&&(elements[i].access_no>key.access_no)){
            elements[i+1] = elements[i];
            i = i-1;
        }
        elements[i+1] = key;
    }
    for(i=0;i<n;i++){
        cout<<elements[i].title<<"\n"<<elements[i].author_name<<"\n"<<elements[i].access_no<<"\n"<<
        elements[i].price<<"\n";
    }
}
