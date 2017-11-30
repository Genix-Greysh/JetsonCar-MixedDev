g++ `pkg-config opencv --cflags` -o camera_stream OpenCV_Camera_Stream.cpp -L/usr/lib/ -L/usr/local/cuda/lib -lcufft -lnpps -lnppi -lnppc -lcudart -lrt -lpthread -lm -ldl  `pkg-config opencv --libs` 
