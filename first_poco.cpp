#include <Poco/Net/HTTPClientSession.h>

int main()
{
    std::string socketFilename = "/path/to/some/domain.socket";
    Poco::Net::HTTPClientSession session(
        Poco::Net::SocketAddress(Poco::Net::SocketAddress::UNIX_LOCAL,
                                 socketFilename));

        return 0;
}
