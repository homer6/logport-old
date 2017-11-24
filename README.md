Logport
-------

Logport is a simple stdin to kafka log exporter. It will save log entries to disk if disconnected from kafka and replay them once it reconnects.



Initial Project
---------------

```
git submodule update --init --recursive
```



Install librdkafka
------------------

Requirements:

The GNU toolchain
GNU make
pthreads
zlib (optional, for gzip compression support)
libssl-dev (optional, for SSL and SASL SCRAM support)
libsasl2-dev (optional, for SASL GSSAPI support)

```
pushd third_party/librdkafka
./configure
make -j12
sudo make install
popd
```



Install cppkafka
----------------

Requirements:

librdkafka

```
pushd third_party/cppkafka
cmake .
make -j12
sudo make install
popd
```



Install cmake version 3 (linux)
-------------------------------

```
mkdir ~/cmake
pushd ~/cmake
wget https://cmake.org/files/v3.10/cmake-3.10.0-Linux-x86_64.sh
chmod ugo+x cmake-3.10.0-Linux-x86_64.sh
./cmake-3.10.0-Linux-x86_64.sh
cd /usr/bin/
ln -s /root/cmake/cmake-3.10.0-Linux-x86_64/bin/cmake
popd
```



Install aws-sdk-cpp
-------------------

```
pushd third_party/aws-sdk-cpp
mkdir build
cd build
cmake ..
make -j12
sudo make install
popd
```




Install logport
----------------

```
cmake .
make
make install
ldconfig
```


Running logport
---------------

```
tail -f some-log-file.log | logport 127.0.0.1:9092 my-topic
```


Cleaning Up
---------------

```
cd third_party/cppkafka
git reset --hard HEAD
git clean -fd
cd ../..

cd third_party/librdkafka
git reset --hard HEAD
git clean -fd
cd ../..
```
