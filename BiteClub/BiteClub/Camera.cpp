#include "Camera.h"
#include <math.h>

using namespace types;

Camera::Camera(){
	m_rotateSpeed = 0.0f;
	m_moveSpeed = 0.0f;
	position = Vector3D(0.0f, 0.0f, 0.0f);
	right = Vector3D(1.0f, 0.0f, 0.0f);
	up = Vector3D(0.0f, 1.0f, 0.0f);
	forward = Vector3D(0.0f, 0.0f, 1.0f);
	viewMatrix = Matrix4x4(Vector4D(1.0f, 0.0f, 0.0f, 0.0f),
	                       Vector4D(0.0f, 1.0f, 0.0f, 0.0f),
	                       Vector4D(0.0f, 0.0f, 1.0f, 0.0f),
	                       Vector4D(0.0f, 0.0f, 0.0f, 1.0f));
	float horizontalAngle=0;
	float verticalAngle=0;
}

void Camera::transformView(float deltaX, float deltaY, float deltaZ, float deltaXAngle, float deltaYAngle, float deltaZAngle){
	//2 and 3 are your x and z change
	moveLeftRight(deltaX, deltaZ);
	moveUpDown(deltaY);
	moveForwardBack(deltaX, deltaZ);
	//rotateX(deltaXAngle);
	//rotateY(deltaYAngle);
	horizontalAngle = deltaXAngle;
	verticalAngle = deltaYAngle;
	rotateZ(deltaZAngle);

	viewMatrix.columns[0] = Vector4D(right.x, right.y, right.z, 0);
	//viewMatrix.columns[1] = Vector4D(up.x, up.y, up.z, 0);
	//viewMatrix.columns[2] = Vector4D(forward.x, forward.y, forward.z, 0);
	viewMatrix.columns[2] = Vector4D (
    cos(verticalAngle) * sin(horizontalAngle),
    sin(verticalAngle),
    cos(verticalAngle) * cos(horizontalAngle), 0.0f
);
	viewMatrix.columns[3] = Vector4D(position.x, position.y, position.z, 1);
}

//walking should be dependant on where the camera is looking, currently is just a generic back and forth 
//something weird af need both for actual proper movement
void Camera::moveForwardBack(float amountx, float amountz){
	// This makes the movement occur only on the x and z axes, mimicking walking.
	position.x += (forward.x * amountx * m_moveSpeed *viewMatrix.columns[2].x);
	//viewMatrix.columns[2].x;
	//viewMatrix.columns[2].z;
	position.z += (forward.z * amountz * m_moveSpeed*viewMatrix.columns[2].z);
}

void Camera::moveLeftRight(float amountx, float amountz){
	// This makes the movement occur only on the x and z axes, mimicking walking.
	position.x += (right.x * amountx * m_moveSpeed*viewMatrix.columns[2].x);
	position.z += (right.z * amountz * m_moveSpeed*viewMatrix.columns[2].z);
}

void Camera::moveUpDown(float amount){
	// This makes the movement occur only on the global y-axis, mimicking jumping.
	position.y += amount;
}

void Camera::rotateX(float angle){

}

void Camera::rotateY(float angle){
	// THERE MAY BE SOMETHING WRONG IN HERE!
	Vector3D newForward = forward, newRight = right;

	angle *= m_rotateSpeed;
	angle *= (PI/180.0f);

	forward.x = (cos(angle + (PI / 2)) * newForward.x) + (cos(angle) * newRight.x);
	forward.y = (cos(angle + (PI / 2)) * newForward.y) + (cos(angle) * newRight.y);
	forward.z = (cos(angle + (PI / 2)) * newForward.z) + (cos(angle) * newRight.z);

	right.x = (cos(angle) * newForward.x) + (cos(angle - (PI / 2)) * newRight.x);
	right.y = (cos(angle) * newForward.y) + (cos(angle - (PI / 2)) * newRight.y);
	right.z = (cos(angle) * newForward.z) + (cos(angle - (PI / 2)) * newRight.z);

	forward = forward.normalise();
	right = right.normalise();
}

void Camera::rotateZ(float angle){

}
