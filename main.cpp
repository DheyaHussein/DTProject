///Copy Right for Diheyea Hussien///

#include<iostream>
#include<stdlib.h>
                                       ///////////////////////
                                       //DS for soleving ///////
									   //polynomial equation////////
									   // using single linked liste/
                                       /////////////////////////////
using namespace std;       
struct sll          
{
	                             
	float cofe;
	int expo;
	sll *link;
};
//to allocated momray for the node
sll* getNode ()
{
	
	return((sll*)malloc(sizeof(sll)));	
}
// function to chacke and insert node dapinding on the sorting 
sll* insertPoly (sll*start ,int ex , float cof)
{
	sll* temp;
	sll*p;
	temp=getNode();
	temp->cofe=cof;
	temp->expo=ex;
    temp->link=NULL;
	
	if (start==NULL || ex>start->expo)
	{
		//insert in the first //
		temp->link=start;
		start=temp;	
	}
	else 
	{
		//insert in end //
		p=start;
		while (p->link != NULL &&p->link->expo>ex)
		
			p=p->link;
			temp->link=p->link;
			p->link=temp;
			if (p->link==NULL)
			temp->link=NULL;	
	}
	return start;
	
}//End of insert //
sll* enter(sll*stert)
{
	int n,expo;
	float cof;
	
	

	cout<<"How many terma you want to enter?";
	cin>>n;
	cout<<"                                             \t \t# \n";
	for(int i=0;i<n;i++)
	{
		cout<<"Enter the coefficient for the tarme "<<i+1<<":";
		cin>>cof;
		cout<<"                                          \t \t# \n";
		cout<<"Enter the expo for the tarme "<<i+1<<":";
		cin>>expo;
		cout<<"                                          \t \t# \n";
		stert=insertPoly(stert , expo,cof);
	}
	return stert;	
}

//function to add two polynomials
sll* addPoly(sll*p1,sll*p2)
{
	
	sll*ptr1=p1;
	sll*ptr2=p2;
	sll*p3_start=NULL;
	
	while(ptr1!=NULL && ptr2!=NULL)
	{
		if (ptr1->expo==ptr2->expo)
		{
			//polynomial creat and stor the result of adding two polynomials 
			p3_start= insertPoly(p3_start,ptr1->expo ,ptr1->cofe + ptr2->cofe);//or p2->expo
			ptr1=ptr1->link;
			ptr2=ptr2->link;
		}
		else if(ptr1->expo > ptr2->expo)
		{
			p3_start=insertPoly(p3_start,ptr1->expo,ptr1->cofe);
			ptr1=ptr1->link;
		}
		else if(ptr2->expo > ptr1->expo)
		{
			p3_start=insertPoly(p3_start,ptr2->expo,ptr2->cofe);
			ptr2=ptr2->link;
		}
	} 
	while(ptr1!=NULL)
	{
		p3_start=insertPoly(p3_start,ptr1->expo,ptr1->cofe);
		ptr1=ptr1->link;
	}
		while(ptr2!=NULL)
	{
		p3_start=insertPoly(p3_start,ptr2->expo,ptr2->cofe);
		ptr2=ptr2->link;
	}
	
	//display(p3_start);
	return p3_start;	
}
sll* subtractPolt(sll*p1,sll*p2)
{
	
	sll*ptr1=p1;
	sll*ptr2=p2;
	sll*p3_start=NULL;
	 
	while(ptr1!=NULL && ptr2!=NULL)
	{
		if (ptr1->expo==ptr2->expo)
		{
			//polynomial creat and stor the tesult of subtract two polynomials 
			p3_start= insertPoly(p3_start,ptr1->expo ,ptr1->cofe - ptr2->cofe);//or p2->expo
			ptr1=ptr1->link;
			ptr2=ptr2->link;
		}
		else if(ptr1->expo > ptr2->expo)
		{
			p3_start=insertPoly(p3_start,ptr1->expo,ptr1->cofe);
			ptr1=ptr1->link;
		}
		else if(ptr2->expo > ptr1->expo)
		{
			p3_start=insertPoly(p3_start,ptr2->expo,ptr2->cofe);
			ptr2=ptr2->link;
		}
	} 
	while(ptr1!=NULL)
	{
		p3_start=insertPoly(p3_start,ptr1->expo,ptr1->cofe);
		ptr1=ptr1->link;
	}
		while(ptr2!=NULL)
	{
		p3_start=insertPoly(p3_start,ptr2->expo,ptr2->cofe);
		ptr2=ptr2->link;
	}
	
	
	return p3_start;	
}

void display(sll*p)
{
	
	//check if the list is empty and print that
	if(p==NULL)
	{
	cout<<"SORRY the list is empty\n";
	return ;	
	}
	sll*tmep;
	//print the conf and expo of the nodes one by one
	 tmep=p;
	while (tmep!=NULL)
	{
		cout<<"("<<tmep->cofe<<"x^"<<tmep->expo<<")";
		tmep=tmep->link;
     	if(tmep!=NULL)
		cout<<"+";
		else
		cout<<"\n";	
	}
	cout<<endl;
}


//founctoin to multiples 
sll* Multiplies (sll*p1,sll*p2)
{
	sll*ptr1=p1,*ptr2=p2;
	sll*p3_start=NULL;

	while (ptr1!=NULL)
	{
		ptr2=p2;
		while(ptr2!=NULL)
		{
		
			p3_start=insertPoly(p3_start,ptr1->expo+ptr2->expo,ptr1->cofe*ptr2->cofe);
			ptr2=ptr2->link;
		}
		
		ptr1=ptr1->link;
	}
	//return p3_start;
	display(p3_start);
 
	return p3_start ;
}
//founctoin to search in the list//
void search(sll*p1,sll*p2)
{
	sll*ptr=p1,*ptr2=p2;
	sll*term=NULL;
	int ex;
	float cof;
	cout<<"enter the the term that want to find\n";
	cout<<"enter the cofntion of that term:\n";
	cin>>cof;
	cout<<"enter the expontion of that term:\n";
	cin>>ex;
	term=insertPoly(term,ex,cof);
	
	//ptr=p1;
	
	while(ptr!=NULL||ptr2!=NULL)
	{
		if (ptr->cofe==term->cofe&&ptr->expo==term->expo)
		{
			cout<<"the term is fonde in the first polynomail.\n\n";
			return;
		}
		else
		ptr=ptr->link;
		
			if (ptr2->cofe==term->cofe&&ptr2->expo==term->expo)
		{
			cout<<"the term is fonde in the scande polynomail.\n\n";
			return;
		}
		else
		ptr2=ptr2->link;
		
		
		
	}
	if (ptr==NULL)
	cout<<"the term is not fonde in the first polynomail.\n\n";
	else
	cout<<"the term is not fonde in the secand polynomail.\n\n";
}
void storing(sll*p3)
{
		sll*ptr3=p3,*tmp=NULL;
	//ptr3=p3_start;
	//tmp=NULL;
	while(ptr3->link!=NULL)
	{
		if(ptr3->expo==ptr3->link->expo)
		{
			ptr3->cofe=ptr3->cofe+ptr3->link->cofe;
			tmp=ptr3->link;
			
			ptr3=ptr3->link->link;
			free(tmp);
			//tmp=NULL;
			//return;
		}
		else{
			ptr3=ptr3->link;
		}
		
	}
	display(p3);
}
void propet()
{
		cout<<"**********WELCOME*************\n \n";

	cout<<"########################################################\n";
	cout<<"this program is a Data Structures empentions of the single linked list\n";
	cout<<"Please enter the polynomial equaotoins \n\n";
}
void Delete (sll*p1,sll*p2)
{
	int expo;
	float cof;
	sll*ptr1=p1,*ptr2=p2,*temp;
	cout<<"enter the data of the term that you want to delete\n";
	cout<<"enter cofetion:\n";
	cin>>cof;
	cout<<"enter expontion:\n";
	cin>>expo;
	if(ptr1->cofe==cof&&ptr1->expo==expo)
	{
		temp=p1;
		p1=temp->link;
		delete(temp);/*First element deleted in the first polynomail */
		cout<<"term deleted from the first polynomail";
		return;
		
	}
		if(ptr2->cofe==cof&&ptr2->expo==expo)
	{
		temp=p2;
		p2=temp->link;
		delete(temp);/*First element deleted in the second polynomail*/
		cout<<"term deleted from the second polynomail";
		return;
		
	}
	ptr1=p1;
	while(ptr1->link->link!=NULL||ptr2->link->link!=NULL)
	{
		if(ptr1->link->cofe==cof&&ptr1->link->expo==expo)/*Element deleted in between*/
		{
			temp=ptr1->link;
			ptr1->link=temp->link;
			delete(temp);
			cout<<"term deleted from the first polynomail\n";
				return;
		}
		else if(ptr2->link->cofe==cof&&ptr2->link->expo==expo)
		{
			temp=ptr2->link;
			ptr2->link=temp->link;
			delete(temp);
			cout<<"term deleted from the second polynomail\n";
				return;
		}
		ptr1=ptr1->link;
		ptr2=ptr2->link;
	
	}/*End of while */
	 /*Last element deleted*/
	if(ptr1->link->cofe==cof&ptr1->link->expo==expo)
	{
		temp=ptr1->link;
		delete(temp);
		ptr1->link=NULL;
		return;
	}
     else if(ptr2->link->cofe==cof&ptr2->link->expo==expo)
	{
		temp=ptr2->link;
		delete(temp);
		ptr2->link=NULL;
		cout<<"term deleted from the second polynomail\n";
		return;
	}
	else 
	cout<<"the data of the term are not found\n";
}

int main ()
{
	
	sll*pol1=NULL;
	sll*pol2=NULL;
	sll*pol3=NULL;
	int flage;
	
propet();
        cout<<" polynomial 1\n";
	    pol1=enter(pol1);
	    display(pol1);
    	cout<<" polynomial 2\n";
    	pol2=enter(pol2);
        display(pol2);
		
	
	
	do
	{
		cout<<"***************MAIN MENU *********************\n";
		cout<<"1:For adding polynomial press number:1  \t \t# \n";
		cout<<"2:For subtract polynomial press number:2 \t \t#\n";
		cout<<"3:For multiplies polynomial press number:3 \t \t# \n";
		cout<<"4:For updating the polynomial press number:4 \t \t# \n";
		cout<<"5:For search about any term in the two Polynomails:5 \t \t# \n";
		cout<<"6:For delete  any term in the two Polynomails:6 \t \t# \n";
		cout<<"7:For exite press:7                         \t \t#\n";
		cin>>flage;
		cout<<"                                           \t \t# \n";
	
	switch(flage)
	{
	
		case 1:
		 pol3=addPoly(pol1,pol2);
	     cout<<"The result is\n";
		 display(pol3);
		 break;
		 case 2:
		 pol3= subtractPolt(pol1,pol2);
		 cout<<"The result is\n";
		 display(pol3);
		 break;
		 case 3:
		pol3= Multiplies(pol1,pol2);
		cout<<"The result is\n";
		 storing(pol3);
		 break;
          case 4:
 	     cout<<" polynomial 1\n";
	     pol1=enter(pol1);
	     display(pol1);
    	 cout<<" polynomial 2\n";
         pol2=enter(pol2);
         break;
          case 5:
         search(pol1,pol2);
         break;
         case 6:
         Delete(pol1,pol2);
         break;
	
         case 7:
         cout<<"bye.........^_^\n";
         cout<<"################################################\n";
         break;
         default:
         cout<<"wrong potion\n";
         break;
	}
	}
	
	while(flage!=7);
}
	