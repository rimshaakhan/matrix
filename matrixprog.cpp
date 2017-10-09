#include<iostream>

using namespace std;
class matrix{
	int matrix1[50][50],matrix2[50][50],i,j,rows,col;
	public: 
		void readmatrix();
		void printmatrix();
		void transposematrix();
		matrix operator*(matrix);
};

void matrix :: readmatrix(){
	cout<<"Enter the number of rows of the matrix:  ";
	cin>>rows;
	cout<<"Enter the number of columns of the matrix:  ";
	cin>>col;
	cout<<"Enter your matrix:";
	for(i=0; i<rows; i++){
		for(j=0; j<col; j++){
			cin>>matrix1[i][j];
		}
	}
}

void matrix:: printmatrix(){
	cout<<"Your entered matrix is:\n";
	for(i=0; i<rows; i++){
		for(j=0;j<col; j++){
			cout<<matrix1[i][j];
			cout<<"  ";
		}
	cout<<"\n";
	}
}

void matrix:: transposematrix(){
	for(i=0; i<rows; i++){
		for(j=0; j<col; j++){
			matrix2[i][j]=matrix1[j][i];
			cout<<matrix2[i][j];
		}
	cout<<"\n";
	}
}

matrix matrix::operator*(matrix a){
	int k;
	matrix temp;
	temp.rows=rows;
	temp.col=a.col;
	for (i=0; i<temp.rows; i++){
		for(j=0; j<temp.col; j++){
			temp.matrix1[i][j]=0;
			for(k=0; k<col; k++)
				temp.matrix1[i][j]+=matrix1[i][k]*a.matrix1[k][j];
			
		}
	}
	return temp;
}

	
	
int main(){
	matrix m,m1,m2;
	int choice;
	char ch;
	do{
	cout<<" Enter your choice:  ";
	cout<<" 1: Enter your matrix\n ";
	cout<<" 2: Print your matrix\n ";
	cout<<" 3: Transpose your matrix\n ";
	cout<<" 4: Find the matrix product\n ";
	cin>>choice;
	
	switch(choice){
	case 1: m.readmatrix();
		m.printmatrix();
		break;
	case 2: m.printmatrix();
		break;
	case 3: m.transposematrix();
		break;
	case 4: m.readmatrix();
		m1.readmatrix();
		m2=m*m1;
		m2.printmatrix();
	default: cout<<"Wrong choice ";
	}
	cout<<"Another attempt..?? (y/n) ";
	cin>>ch;
	}
	while (ch!= 'n');
	cout<<"\n";
	
}
