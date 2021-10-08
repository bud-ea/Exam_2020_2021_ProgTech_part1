FROM ubuntu

LABEL author="Gordeychuk"

RUN echo "This image made as an exam task by Nikita Gordeychuk"

RUN apt update -y && apt upgrade -y \
&& apt install -y build-essential g++

COPY Exam_proj_QtLess /app/source

WORKDIR /app/source
RUN g++ *.cpp -o ../myProgram

WORKDIR /app

ENTRYPOINT [ "/app/myProgram" ]