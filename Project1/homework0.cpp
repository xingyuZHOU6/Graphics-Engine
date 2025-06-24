#include<iostream>
#include<Eigen>
#include<cmath>
#define PI 3.14159265358979323846
using namespace std;
int main()
{
	// ��ʽģ�嶨�� (3��1��)
	Eigen::Matrix<double, 3, 1> mat;

	// ��ʼ��������
	mat <<2,1,1;

	//�任����
	Eigen::Matrix3d rotation_matrix;
	double angle = 45 * PI / 180; // �Ƕ�ת��Ϊ����	
	rotation_matrix << cos(angle), -sin(angle), 1,
					  sin(angle), cos(angle), 2,
		              0, 0, 1;
	// ������
	Eigen::Matrix<double, 3, 1> result = rotation_matrix * mat;
	// ������
	cout << "Result of the transformation:\n" << result << endl;
}