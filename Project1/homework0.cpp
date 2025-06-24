#include<iostream>
#include<Eigen>
#include<cmath>
#define PI 3.14159265358979323846
using namespace std;
int main()
{
	// 显式模板定义 (3行1列)
	Eigen::Matrix<double, 3, 1> mat;

	// 初始化方法：
	mat <<2,1,1;

	//变换矩阵
	Eigen::Matrix3d rotation_matrix;
	double angle = 45 * PI / 180; // 角度转换为弧度	
	rotation_matrix << cos(angle), -sin(angle), 1,
					  sin(angle), cos(angle), 2,
		              0, 0, 1;
	// 计算结果
	Eigen::Matrix<double, 3, 1> result = rotation_matrix * mat;
	// 输出结果
	cout << "Result of the transformation:\n" << result << endl;
}