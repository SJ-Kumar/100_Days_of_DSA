/*
Bidirectional Selection Sort Students
Selection sort technique has the core idea of choosing the apt element for the ith position. This technique will be having 'i' sorted elements from the beginning of the array after 'i' iterations. In each iteration, this technique basically find the minimum element from the unsorted array. Bidirectional Selection sort is a variation of selection sort which sort the elements from both the directions. We will have two indices pointing to the extreme ends and we move them in opposite direction till they cross each other. The algorithm works as below:

1. Let i = 1 and j = n

2. Repeat step 2 to 10 when i < j

3. Initialize min = max = ith element

4. Initialize min_index and max_index to i

5. Let k = i

6. while k<=j do steps 7 and 8

7. if element in kth position is greater than max then make max as kth element and max_index as k

8. Else if the element in kth position is less than max then make min as kth element and min_index as k

9. swap element at ith position and min

10. swap eleeent at jth position and max

Consider a vector of student records as shown in the post code and sort them based on roll no using Bidirectional Selection sort. Understand the precode of Bidirectional Selection sort given and complete

Note:

1. Use getline(cin,s) to read string in this code

2. Use cin.ignore()  to clear one or more characters from the input buffer if normal cin was used to read previous input

Input Format

First line cotains the number of students, n

Next 3*n lines contain details of students in the order name, rollno and marks of each student

Output Format

Print details of students sorted as per rollnp in ascending order print name, rollno and marks of each student in order



*/

#include<iostream>
using namespace std;
#include<vector>
class student
{
	string name;
	int rollno;
	int marks;
	public:
	friend istream& operator>>(istream&, student&);
	friend ostream& operator<<(ostream&,student&);
	bool operator<(student&);
	bool operator>(student&);	
};
// values are passed by reference
void swap(int &a, int & b)
{
		int temp;
		temp = a;
		a = b;
		b = temp;
}
// Vector is passed by reference
void bidirectional_selection_sort(vector<student>& elements)
{
	int n = elements.size(),i=0,j=n-1,min_i,max_i,k,p;
	student max,min;
	//Initialize min and max to first elements of unsorted array
	// Move i in forward and j in reverse direction
	while(i<=j)
	{
		//Initialize min and max to first elements in the same for loop
		min = elements[i];
		max = elements[i];
		//min index and max index to 0
		min_i = i;
		max_i = i;
		// Move k from index i to index j (inclusive)
		k=i;
		while(k<=j)
		{
			if(elements[k]>max)
			{
				max = elements[k];
		        max_i = k;
		    }
			else if(elements[k]<min)
			{	
                min = elements[k];
                min_i = k;
			}
			k++;
		}
		/*swap(elements[i], elements[min_i]);
		swap(elements[j], elements[max_i]);*/
		student temp;
		
		// swap element in the first position of unsorted array to minimum element
		temp=elements[i];
		elements[i]=elements[min_i];
		elements[min_i]=temp;
		
		// and element in last position of unsorted array to maximum element
		temp=elements[j];
		elements[j]=elements[max_i];
		elements[max_i]=temp;
		
		i++;
		j--;
	}
	cout<<"\nabc\n\n";
}
istream& operator>>(istream& in,student& s)
{
    cin.ignore();
    getline(in,s.name);
    in>>s.rollno>>s.marks;
    return in;
}
ostream& operator<<(ostream& out,student& s)
{
    out<<s.name<<"\n"<<s.rollno<<"\n"<<s.marks<<endl;
    return out;
}
bool student::operator<(student& s)
{
    return (rollno<s.rollno);
}
bool student::operator>(student& s)
{
    return (rollno>s.rollno);
}

int main()
{
	vector<student> elements;
	int i,n;
	student ele;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>ele;
		elements.push_back(ele);
	}
	bidirectional_selection_sort(elements);
	for(i=0;i<n;i++)
		cout<<elements[i];
}
