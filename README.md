

git submodule update --init --recursive


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
cd third_party/librdkafka
./configure
make -j12
sudo make install
cd ../..
```


Install cppkafka
----------------

Requirements:

librdkafka

```
cd third_party/cppkafka
cmake .
make -j12
sudo make install
cd ../..
```


Install logport
----------------

cmake .
make
make install
ldconfig



Running logport
---------------

tail -f some-log-file.log | logport 127.0.0.1:9092 my-topic