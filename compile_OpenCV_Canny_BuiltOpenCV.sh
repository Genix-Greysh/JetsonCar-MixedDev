#g++ OpenCV_Canny.cpp -I/usr/local/include/opencv  -L/usr/local/lib/ 
#	-lopencv_contrib  -lopencv_core -lopencv_features2d  -lopencv_flann 
#	-lopencv_gpu  -lopencv_highgui  -lopencv_imgproc -lopencv_legacy  -lopencv_ml  
#	-lopencv_nonfree -lopencv_objdetect -lopencv_ocl -lopencv_photo  -lopencv_stitching 
#	-lopencv_superres  -lopencv_video  -lopencv_videostab  
#	-L/usr/local/cuda/lib -lcufft -lnpps -lnppi -lnppc -lcudart -lrt -lpthread -lm -ldl  -o camera_canny

g++ `pkg-config opencv --cflags` -o camera_canny OpenCV_Canny.cpp -L/usr/lib/ -L/usr/local/cuda/lib -lcufft -lnpps -lnppi -lnppc -lcudart -lrt -lpthread -lm -ldl  `pkg-config opencv --libs` 
