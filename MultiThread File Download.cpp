#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include "string.h"
#pragma comment(lib, "urlmon.lib")
#include <urlmon.h>
#include <string>
#include <fstream>
#define getURL URLOpenBlockingStream
using namespace std;


using namespace std;

#define NUM_THREADS 4

#define RECEIVE_THREAD_0 0
#define RECEIVE_THREAD_1 1
#define RECEIVE_THREAD_2 2
#define RECEIVE_THREAD_3 3

#define NUMBER_STRING_BYTES 15

int ProgressFile1=0;
int ProgressFile2=0;
int ProgressFile3=0;

const char* URL1 = "https://file-examples-com.github.io/uploads/2017/10/file_example_PNG_3MB.png";
const char* URL2 = "https://file-examples-com.github.io/uploads/2017/10/file_example_PNG_3MB.png";
const char* URL3 = "https://file-examples-com.github.io/uploads/2017/10/file_example_PNG_3MB.png";

long map(long x, long in_min, long in_max, long out_min, long out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void *ReceiveFunc_0(void *) {

  // Windows IStream interface 
  IStream* stream;
  // make a call to the URL 
  // a non-zero return means some error 
  if (getURL(0, URL1, &stream, 0, 0))
  {
    cout << "Error occured.";
    cout << "Check internet";
    cout << "Check URL. Is it correct?";
  }
  // this char array will be cyclically 
  // filled with bytes from URL 
  char buff2[100];
  char buff[100];
  // we shall keep appending the bytes 
  // to this string 
  string s;
  unsigned long bytesRead;
  unsigned long bytesRead1;
  int totalBytes=0;
  while(true)
  {
  	stream->Read(buff2, 100, &bytesRead1);
	totalBytes=totalBytes+bytesRead1;
    if(0U == bytesRead1)
    {
      break;
    }
  }
  if (getURL(0, URL1, &stream, 0, 0))
  {
    cout << "Error occured.";
    cout << "Check internet";
    cout << "Check URL. Is it correct?";
  }
  int tempVar=0;
  while(true)
  {
    // Reads a specified number of bytes 
    // from the stream object into char 
    // array and stores the actual 
    // bytes read to "bytesRead" 
    stream->Read(buff, 100, &bytesRead);
    tempVar=tempVar+bytesRead;	
	ProgressFile1= map(totalBytes-tempVar,totalBytes,0,0,100);
    if(0U == bytesRead)
    {
      break;
    }
    // append and collect to the string 
    s.append(buff, bytesRead);
  };
  // release the interface 
  // good programming practice 
  stream->Release();
  ofstream myfile;
  myfile.open ("file1.png");
  myfile << s;
  myfile.close();
  pthread_exit(NULL);
}

void *ReceiveFunc_1(void *) {

  // Windows IStream interface 
  IStream* stream;
  // make a call to the URL 
  // a non-zero return means some error 
  if (getURL(0, URL2, &stream, 0, 0))
  {
    cout << "Error occured.";
    cout << "Check internet";
    cout << "Check URL. Is it correct?";
  }
  // this char array will be cyclically 
  // filled with bytes from URL 
  char buff2[100];
  char buff[100];
  // we shall keep appending the bytes 
  // to this string 
  string s;
  unsigned long bytesRead;
  unsigned long bytesRead1;
  int totalBytes=0;
  while(true)
  {
  	stream->Read(buff2, 100, &bytesRead1);
	totalBytes=totalBytes+bytesRead1;
    if(0U == bytesRead1)
    {
      break;
    }
  }
  if (getURL(0, URL2, &stream, 0, 0))
  {
    cout << "Error occured.";
    cout << "Check internet";
    cout << "Check URL. Is it correct?";
  }
  int tempVar=0;
  while(true)
  {
    // Reads a specified number of bytes 
    // from the stream object into char 
    // array and stores the actual 
    // bytes read to "bytesRead" 
    stream->Read(buff, 100, &bytesRead);
    tempVar=tempVar+bytesRead;	
	ProgressFile2= map(totalBytes-tempVar,totalBytes,0,0,100) ;
    if(0U == bytesRead)
    {
      break;
    }
    // append and collect to the string 
    s.append(buff, bytesRead);
  };
  // release the interface 
  // good programming practice 
  stream->Release();
  ofstream myfile;
  myfile.open ("file2.png");
  myfile << s;
  myfile.close();
  pthread_exit(NULL);
}

void *ReceiveFunc_2(void *) 
{
  // Windows IStream interface 
  IStream* stream;
  // make a call to the URL 
  // a non-zero return means some error 
  if (getURL(0, URL3, &stream, 0, 0))
  {
    cout << "Error occured.";
    cout << "Check internet";
    cout << "Check URL. Is it correct?";
  }
  // this char array will be cyclically 
  // filled with bytes from URL 
  char buff2[100];
  char buff[100];
  // we shall keep appending the bytes 
  // to this string 
  string s;
  unsigned long bytesRead;
  unsigned long bytesRead1;
  int totalBytes=0;
  while(true)
  {
  	stream->Read(buff2, 100, &bytesRead1);
	totalBytes=totalBytes+bytesRead1;
    if(0U == bytesRead1)
    {
      break;
    }
  }
  if (getURL(0, URL3, &stream, 0, 0))
  {
    cout << "Error occured.";
    cout << "Check internet";
    cout << "Check URL. Is it correct?";
  }
  int tempVar=0;
  while(true)
  {
    // Reads a specified number of bytes 
    // from the stream object into char 
    // array and stores the actual 
    // bytes read to "bytesRead" 
    stream->Read(buff, 100, &bytesRead);
    tempVar=tempVar+bytesRead;	
	ProgressFile3= map(totalBytes-tempVar,totalBytes,0,0,100);
    if(0U == bytesRead)
    {
      break;
    }
    // append and collect to the string 
    s.append(buff, bytesRead);
  };

  // release the interface 
  // good programming practice 
  stream->Release();
  ofstream myfile;
  myfile.open ("file3.png");
  myfile << s;
  myfile.close();
  pthread_exit(NULL);
}

void *ReceiveFunc_3(void *) 
{
	while(1)
	{
		cout << "Progress File 1: "	<< ProgressFile1 << " Progress File 2: "	<< ProgressFile2 << " Progress File 3: "	<< ProgressFile3 << endl;
		if(ProgressFile1 == 100 and ProgressFile2 == 100 and ProgressFile3 == 100)
		{
			cout << "Progress File 1: "	<< ProgressFile1 << " Progress File 2: "	<< ProgressFile2 << " Progress File 3: "	<< ProgressFile3 << endl;
			cout << "Finished" << endl;
			break;	
		}
	}
	pthread_exit(NULL);
}

void makeThreads(void)
{
    int rc;
    pthread_t threads[NUM_THREADS];
    /* Creating the First Function for File Receive */
    rc = pthread_create(&threads[RECEIVE_THREAD_0], NULL, ReceiveFunc_0, NULL);
    if (rc) 
    {
        cout << "Error:unable to create thread first," << rc << endl;
        exit(-1);
    }
    /* Creating the Second Function for File Receive */
    rc = pthread_create(&threads[RECEIVE_THREAD_1], NULL, ReceiveFunc_1, NULL);
    if (rc) 
    {
        cout << "Error:unable to create thread two," << rc << endl;
        exit(-1);
    }
    /* Creating the Third Function for File Receive */
    rc = pthread_create(&threads[RECEIVE_THREAD_2], NULL, ReceiveFunc_2, NULL);
    if (rc) 
    {
        cout << "Error:unable to create thread three," << rc << endl;
        exit(-1);
    }
    /* Creating the Fourth Function for File Receive */
    rc = pthread_create(&threads[RECEIVE_THREAD_3], NULL, ReceiveFunc_3, NULL);
    if (rc) 
    {
        cout << "Error:unable to create thread four," << rc << endl;
        exit(-1);
    }

    
}
int main () 
{   
   makeThreads();
   pthread_exit(NULL);
}


