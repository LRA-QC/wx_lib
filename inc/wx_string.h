#include <string.h>
#include <cstdlib>

#ifndef _H_WX_STRING
#define _H_WX_STRING
namespace wx 
{
  class string  
  {
    private:
      char *buffer{};
      unsigned int size_current{};
      unsigned int size_buffer{100};

      /// Copy text to internal buffer variable
      void assign(const char *text)
      {
        int k = strlen(text);   //TODO: REPLACE WITH OUR OWN FUNCTION
        #ifdef _DEBUG
          printf("[%d] inputtext: %s [%lu]\n",k,text,sizeof(text));
        #endif //_DEBUG
        if ( k > 0 )
        {
          size_current = k ;
          if ( size_current <= size_buffer )
          {
            buffer=(char *)malloc(size_buffer+1);
            memset(buffer,0,size_buffer);
          }
          else
          {
            size_buffer = size_current + 1;
            buffer=(char *)malloc(size_buffer);
            memset(buffer,0,size_current);
          }
          strncpy(buffer,text,k);
          
        }
        else
        {
            buffer=(char *)malloc(size_buffer+1);
            buffer[0]=0;
            size_current=0;
        }
        #ifdef _DEBUG
          printf("*** ALLOC *** sizebuffer: [%u] sizecurrent: [%u]\n", size_buffer, size_current);
          printf("buffer: %s\n",(char *)buffer);
        #endif //_DEBUG
      }

    public:
      ///Destructor
      ~string() {
        if (buffer) {
          free(buffer);
          buffer=0;
          #ifdef _DEBUG
            printf("*** FREE BUFFER ***\n");
          #endif //_DEBUG
        }
      }
      string() {
        assign("");
      }
      string(const char *text)  {
        assign(text);
      }
      void operator=(const char *text)
      {
        unsigned int k=strlen(text);
        if (k <= size_buffer) //do we need to resize the buffer?
        {
          strncpy(buffer,text,k);
          buffer[k]=0;
          size_current=k;
        }
        else
        {
          if (buffer)
          {
            free(buffer);
            buffer=0;
          }
          size_buffer = k ;
          buffer=(char *)malloc(size_buffer+1);
          memset(buffer,0,size_current);
          strncpy(buffer,text,k);
        }
      }
      ///clear value
      void clear() {
        buffer[0]=0;  //POINTER WILL BE FREED AT THE DESTRUCTION STAGE
        size_current=0;
      }
      ///return pointer (for compatibility with STD::STRING)
      const char * c_str()  { return (const char *) buffer;  }
      ///return the length of the string
      unsigned int length() { return size_current;           }
  }; //END CLASS
};
#endif //_H_WX_STRING