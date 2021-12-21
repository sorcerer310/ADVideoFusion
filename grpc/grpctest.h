#ifndef GRPCTEST_H
#define GRPCTEST_H
#include <QWidget>
#include <grpcpp/grpcpp.h>

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
//using grpc::


//class GreeterServiceImpl final:public RouteGuide::Service{
//    Status SayHello(ServerContext *,const HelloRequest *request, HelloReply *reply) override
//    {
//        std::string prefix("Hello ");
//        reply->set_message(prefix + request->name());
//        return Status::OK;

//    }
//};

class GrpcTest
{
//    Q_OBJECT
public:
    GrpcTest();
};

#endif // GRPCTEST_H
