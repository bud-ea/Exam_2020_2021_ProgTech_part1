FROM ubuntu

LABEL author="Balaev"

RUN echo "This image made as an exam task by Max Balaev"

RUN apt update -y && apt upgrade -y \
&& apt install -y build-essential g++

COPY . ./MyProj

workdir ./MyProj
RUN g++ *.cpp -o ../MyProj


ENTRYPOINT [ "/app/workdir ./MyProj" ]