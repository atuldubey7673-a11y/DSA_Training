// int maxArea(int* height, int heightSize) {
//     int max = 0;
//     for (int i = 0; i < heightSize; i++) {
//         for (int j = i + 1; j < heightSize; j++) {
//             int h;
//             if (height[i] < height[j]) {
//                 h = height[i];

//             } else {
//                 h = height[j];
//             }
//             int width = j - i;
//             int area = h * width;

//             if (area > max) {
//                 max = area;
//             }
//         }
//     }
//     return max;
// }
int maxArea(int* height, int heightSize) {

    int left = 0;
    int right = heightSize - 1;

    int max = 0;

    while(left < right) {

        int h;

        if(height[left] < height[right]) {
            h = height[left];
        } else {
            h = height[right];
        }

        int width = right - left;

        int area = h * width;

        if(area > max) {
            max = area;
        }

        // Move smaller height
        if(height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }

    return max;
}