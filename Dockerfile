FROM ubuntu:22.04

SHELL ["/bin/bash", "-c"]

# Get packages list and user utilities
RUN apt-get update && apt-get install -y jq nano tmux vim cmake g++ git python3 lld

# Set up Emscripten
RUN apt-get install -y xz-utils \
 && git clone https://github.com/emscripten-core/emsdk.git emsdk \
 && cd emsdk \
 && ./emsdk install 3.1.51

RUN cd emsdk \
 && ./emsdk activate 3.1.51

COPY . /softfloat

RUN cd /softfloat/build/WebAssembly \
 && source /emsdk/emsdk_env.sh \
 && make softfloat.wasm
