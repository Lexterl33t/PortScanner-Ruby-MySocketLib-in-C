#include "ruby.h"
#include "extconf.h"
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>


VALUE TCPSock(VALUE self, VALUE ip, VALUE port)
{
    if(RB_TYPE_P(ip, T_STRING) == 0)
    {
        rb_fatal("Ip format must be String");
    }
    if(RB_TYPE_P(port, T_STRING) == 0)
    {
        rb_fatal("port format must be String");
    }
    int sock = socket(0x2, 0x1, 0x0);
    if(sock == -1)
    {
        rb_raise(rb_eStandardError, "Could not create socket");
        return Qnil;
    }
    struct sockaddr_in server;

    server.sin_addr.s_addr = inet_addr(RSTRING_PTR(ip));
    server.sin_port = htons(atoi(RSTRING_PTR(port)));
    server.sin_family = AF_INET;

    if(connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0)
    {
        rb_raise(rb_eStandardError, "Connection refused");
        
        return Qnil;
    }


    return Qnil;
}


void Init_sock()
{
    rb_define_global_function("TCPSock", TCPSock, 2);
}