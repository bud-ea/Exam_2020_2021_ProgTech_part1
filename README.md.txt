FROM ubuntu

LABEL author="Demyanova Natalia"
LABEL group="201-331"

RUN echo "This image made as an exam task by Demyanova Natalia"

RUN apt update -y && apt upgrade -y \
    && apt install -y build-essential g++

COPY Exam_proj_QtLess/app /app/source

WORKDIR /app/source
RUN g++ *.cpp -o /myProgram

WORKDIR /app

ENTRYPOINT [ "/myProgram" ]
