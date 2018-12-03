//to compile: make ObstacleDetector (need opencv libs installed)
//to run: ./ObstacleDetector image.png (the image must be in the same folder as the executable)

#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;

int main(int argc, char **argv){
	int imageX, imageY, edge = 34, i, j, k, w; 
	bool flag = 0;
	Mat image,imageResult;
	image = imread(argv[1],CV_LOAD_IMAGE_GRAYSCALE);
	imageResult = imread(argv[1],CV_LOAD_IMAGE_GRAYSCALE);
	if(!image.data)
		printf("Error: could not open the image.\n");
	imageX = image.rows;
	imageY = image.cols;
    for(k=0; k<imageX; k++){
        for(w=0; w<imageY; w++){
            if(image.at<uchar>(k,w) < 130 && flag == 0){
                flag = 1;                
            }
            if(flag==1){
                for(i=k-(edge/2); i<=k+(edge/2); i++){
                    for(j=w-(edge/2); j<=w+(edge/2); j++){
                        if(i>=0 && j>=0 && i<imageX && j<imageY){ 
                            imageResult.at<uchar>(i,j) = 0;
                        }
                    }
                }
	    }
            else{
                imageResult.at<uchar>(k,w) = 255;
            }
            flag = 0;
        }
    }
	imshow("result", imageResult);
	imshow("original", image);
	imwrite("result.png", imageResult);
	waitKey();
}
