#include<stdio.h>
#define MAX(a,b) ((a>b)?a:b)
#define MAX_DEGREE 50

typedef struct
{
	int degree;				// 다항식의 차수
	float coef[MAX_DEGREE];	// 항의 계수 저장할 배열
}polynomial;

polynomial addPoly(polynomial, polynomial);
void printPoly(polynomial);

void main()
{
	polynomial A = { 3,{4,3,5,0} };
	polynomial B = { 4,{3,1,0,2,1} };

	polynomial C;
	C = addPoly(A, B);	// A,B 덧셈을 수행하기 위해 addPoly 함수 호출

	printf("\n A(x) ="); printPoly(A);
	printf("\n B(x) ="); printPoly(B);
	printf("\n C(x) ="); printPoly(C);

	getchar();
}

// 알고리즘 3-1 : 순차리스트를 이용한 다항식의 덧셈 연산
polynomial addPoly(polynomial A, polynomial B)
{
	polynomial C;
	int A_index = 0, B_index = 0, C_index = 0;
	int A_degree = A.degree, B_degree = B.degree;
	C.degree = MAX(A.degree, B.degree);

	while (A_index <= A.degree && B_index <= B.degree) 
	{
		if (A_degree > B_degree)
		{
			C.coef[C_index++] = A.coef[A_index++];
			A_degree--;
		}
		else if (A_degree == B_degree)
		{
			C.coef[C_index++] = A.coef[A_index++] + B.coef[B_index++];
			A_degree--;
			B_degree--;
		}
		else
		{
			C.coef[C_index++] = B.coef[B_index++];
			B_degree--;
		}
	}
	return C;	// 다항식 덧셈의 결과 다항식 C를 반환
}

void printPoly(polynomial P)
{
	int i, degree;
	degree = P.degree;

	for (i = 0; i <= P.degree; i++)
	{
		printf("%3.0fx^%d", P.coef[i], degree--);
		if (i < P.degree) printf(" +");
	}
	printf("\n");
}