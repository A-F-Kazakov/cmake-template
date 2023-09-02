DOCKER_IMAGE=template:base
BUILD_DIR=/build
INSTALL_DIR=/install
BUILD_TYPE=Debug

base_image:
	DOCKER_BUILDKIT=1 docker build -t $(DOCKER_IMAGE) --ssh default=$(HOME)/.ssh/id_rsa .

config:
	cmake -S. -B$(BUILD_DIR)					\
		-DCMAKE_BUILD_TYPE=$(BUILD_TYPE)		\
		-DCMAKE_EXPORT_COMPILE_COMMANDS=ON	\
		-DCMAKE_MODULE_PATH=/cmake				\
		-DENABLE_CLANG_TIDY=ON					\
		-DENABLE_CLANG_TIDY_FIX_ERRORS=ON	\
		-DENABLE_SANITIZER_ADDRESS=ON			\
		-DENABLE_SANITIZER_LEAK=ON				\
		-DENABLE_SANITIZER_UNDEFINED_BEHAVIOR=ON \
		-DENABLE_SANITIZER_THREAD=OFF			\
		-DENABLE_SANITIZER_MEMORY=OFF			\
		-DTMPL_BUILD_TESTS=ON					\
		-DTMPL_BUILD_EXAMPLES=ON

build:
	cmake --build $(BUILD_DIR) --config $(BUILD_TYPE) -j$(shell nproc)

tests:
	ctest --test-dir $(BUILD_DIR) -C $(BUILD_TYPE) -j$(shell nproc) --output-on-failure 

install:
	cmake --install $(BUILD_DIR) --config $(BUILD_TYPE) --prefix $(INSTALL_DIR)
