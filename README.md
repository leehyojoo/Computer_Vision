
```
Proj1 Image_Rotation
├─ b.png
├─ lena.jpg
├─ main.cpp
├─ _2Image_Rotation.vcxproj
├─ _2Image_Rotation.vcxproj.filters
└─ _2Image_Rotation.vcxproj.user

```

위의 코드는 이미지를 회전시키는 세 가지 방법을 구현함. 

문제는 다음과 같이 3가지임.

1. problem_a_rotate_forward: 이미지를 지정한 각도로 시계 방향으로 회전시킴.
2. problem_b_rotate_backward: 이미지를 지정한 각도로 반시계 방향으로 회전시킴.
3. problem_c_rotate_backward_interarea: 이미지를 지정한 각도로 반시계 방향으로 회전시킨 후, 보간 방법으로 INTER_AREA를 사용하여 원본 크기로 다시 조정함.


위의 문제를 해결하기 위해 다음과 같은 접근 방식을 사용하였음.

- 회전 행렬(Rotation matrix) 계산: cv::getRotationMatrix2D 함수를 사용하여 회전 중심점과 회전 각도를 기반으로 회전 행렬을 계산함.
- 출력 이미지의 범위 계산: cv::RotatedRect와 boundingRect2f 함수를 사용하여 회전된 이미지의 좌표 범위를 계산함.
- 출력 이미지의 크기 조정: rotation_matrix를 사용하여 원본 이미지를 회전 및 이동시킴.
- 필요한 경우 보간 방법 적용: cv::warpAffine 함수를 사용하여 이미지를 회전시키고, cv::resize 함수를 사용하여 INTER_AREA 보간 방법을 적용하여 원본 크기로 조정함.
- 결과 이미지 반환 및 표시: 결과 이미지를 반환하고 imshow 함수를 사용하여 출력함.
- 위의 코드와 접근 방식은 angle 변수에 음수 값을 지정하여 시계 방향으로 회전하는 것을 제외하고는 유사함. 결과 이미지는 imshow 함수를 사용하여 각각 "a_output", "b_output", "c_output" 창에 표시됨.
