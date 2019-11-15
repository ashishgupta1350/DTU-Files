#include<iostream>
using namespace std;

float probHomogenious()
{

	// given the probability of defective is 0.01
	// prob of not defective is 0.99
	// prob that non is defective is 
	float probNoneDefective=pow(0.99,20);
	float probExactly1=pow(0.99,19)*0.01*20; // 20C1 * (.99) ** 19 * .01

	float total = probNoneDefective + probExactly1;
	float ans=1000*total;
	return ans;


}

int main(){

	float sum=0;
	// sum is the prob of n=0; That is no fuse is defective
	for(int i=1;i<=20;i++)
	{
		sum*=(1-(0.01*i));
	}

	float sum_1=0;
	// sum_1 is the prob when exactly 1 is defective
	int index_defective=0;
	for(int i=1;i<=20;i++)
	{
		float productOfProb=1;
		 index_defective++; // initialized to zero
		for(int j=1;j<=20;j++)
		{
			if(j==index_defective)
			{
				productOfProb*=0.01*index_defective;
			}
			productOfProb*=(1-(0.01*j));
		}
		sum_1+=productOfProb;
	}
	// so the probability of p(n<=1) is :
	float probabilityNLessthan2=sum+sum_1;

	// prob of n>=2 is 
	float probabilityNGreaterThan1= 1-probabilityNLessthan2;
	cout<<1000*probabilityNGreaterThan1;


	return 0;

}