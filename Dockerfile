FROM ubuntu:22.04

SHELL ["/bin/bash", "-c"]

# Get packages list and user utilities
RUN apt-get update && apt-get install -y jq nano tmux vim cmake g++ git python lld

# Set up Emscripten
RUN git clone https://github.com/emscripten-core/emsdk.git emsdk \
 && cd emsdk \
 && ./emsdk install 3.1.51

