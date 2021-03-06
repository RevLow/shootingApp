rm -rf install_*
rm -rf output-*

# build simulator
./configure --prefix=`pwd`/install_i386 CFLAGS="-Ofast -mios-version-min=5.0" LDFLAGS="-flto" CC="xcrun -sdk iphonesimulator clang -arch i386"
make clean && make -j8 && make install

./configure --prefix=`pwd`/install_x86_64 CFLAGS="-Ofast -mios-version-min=5.0" LDFLAGS="-flto" CC="xcrun -sdk iphonesimulator clang -arch x86_64"
make clean && make -j8 && make install

# build armv7
./configure --prefix=`pwd`/install_armv7 --enable-arm-neon=api CFLAGS="-Ofast -mios-version-min=5.0" LDFLAGS="-flto" CC="xcrun -sdk iphoneos clang -arch armv7" --host=arm
make clean && make -j8 && make install

# build armv7s
./configure --prefix=`pwd`/install_armv7s --enable-arm-neon=api CFLAGS="-Ofast -mios-version-min=5.0" LDFLAGS="-flto" CC="xcrun -sdk iphoneos clang -arch armv7s" --host=arm
make clean && make -j8 && make install

# build armv7s
./configure --prefix=`pwd`/install_arm64 --enable-arm-neon=api CFLAGS="-Ofast -mios-version-min=5.0" LDFLAGS="-flto" CC="xcrun -sdk iphoneos clang -arch arm64" --host=arm
make clean && make -j8 && make install

# build universal
mkdir -p output-ios
xcrun lipo -create $(find install_*/lib -name "libpng.a") -o output-ios/libpng.a
cp -r install_armv7/include output-ios/.

# build macosx
./configure --prefix=`pwd`/install_macosx CFLAGS="-Ofast -mmacosx-version-min=10.7" LDFLAGS="-flto" CC="xcrun -sdk macosx clang -arch x86_64"
make clean && make -j8 && make install
install_name_tool -id "@executable_path/../Frameworkds/libpng.dylib" install_macosx/lib/libpng.dylib

mkdir -p output-macosx
cp -r install_macosx/include output-macosx/.
LIB=libpng.dylib; while readlink install_macosx/lib/$LIB > /dev/null; do LIB=$(readlink install_macosx/lib/$LIB); done;
cp install_macosx/lib/$LIB output-macosx/libpng.dylib