#include <boost/asio/io_context.hpp>
#include <boost/beast/core.hpp>
#include <boost/version.hpp>
#include <nlohmann/json.hpp>
#include <cstdio>

int main() {
    boost::asio::io_context ioc;               // 只要这行编过，Asio 就通了
    (void)ioc;

    nlohmann::json j = {{"project", "asynclog-cloud"}, {"stage", 1}};

    std::printf("Boost %d.%d.%d | Beast OK | json: %s\n",
                BOOST_VERSION / 100000, BOOST_VERSION / 100 % 1000, BOOST_VERSION % 100,
                j.dump().c_str());
    return 0;
}
