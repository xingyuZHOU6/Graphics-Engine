#include<iostream>
#include<Eigen>
#include<cmath>
#define M_PI 3.14159265358979323846
using namespace std;



/*
     作业要求：
     填写一个旋转矩阵和一个透视投影矩阵。给定三维下三个点 v 0 (2.0,0.0,−2.0), v1 (0.0,2.0,−2.0), 
     v2 (−2.0,0.0,−2.0), 
     你需要将这三个点的坐标变换为屏幕坐标并在屏幕上绘制出对应的线框三角形 (在代码框架中已经提供了 draw_triangle 函数，
     所以只需要去构建变换矩阵即可)。简而言之，需要进行模型、视图、投影、视口等变换来将三角形显示在屏幕上。
     在提供的代码框架中，需要完成模型变换和投影变换的部分。 

*/

Eigen::Matrix4f get_model_matrix(float rotation_angle); //第一个接口函数，获取模型变换矩阵，即返回一个旋转矩阵

// 第二个接口函数，获取透视投影矩阵
Eigen::Matrix4f get_projection_matrix(float eye_fov, float aspect_ratio,
	float zNear, float zFar);

int main()
{
	//定义三个点的齐次坐标
	Eigen::Matrix<double, 4, 1> v0, v1, v2;
	v0 << 2.0, 0.0, -2.0, 1.0;
	v1 << 0.0, 2.0, -2.0, 1.0; 
	v2 << -2.0, 0.0, -2.0, 1.0; 

}
Eigen::Matrix4f get_model_matrix(float rotation_angle) {

	//默认沿z轴旋转
	float angle_rad = rotation_angle * M_PI / 180.0f; // 将角度转换为弧度	
	// 旋转矩阵
	Eigen::Matrix4f rotation_matrix;
	rotation_matrix << cos(angle_rad), -sin(angle_rad), 0, 0,
		sin(angle_rad), cos(angle_rad), 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1;
	return rotation_matrix;
}

Eigen::Matrix4f get_projection_matrix(float eye_fov, float aspect_ratio,
	float zNear, float zFar) {


	// 透视投影矩阵
	float tan_half_fov = tan(eye_fov * M_PI / 360.0f); // 将视场角转换为弧度并计算正切值 这里取一半的视场角
	Eigen::Matrix4f projection_matrix;
	projection_matrix << 1 / (aspect_ratio * tan_half_fov), 0, 0, 0,
		0, 1 / tan_half_fov, 0, 0,
		0, 0, -(zFar + zNear) / (zFar - zNear), -2 * zFar * zNear / (zFar - zNear),
		0, 0, -1, 0; // 注意这里的透视投影矩阵的最后一行
	return projection_matrix;
}