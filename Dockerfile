FROM ubuntu:18.04
LABEL maintainer="Kalacheva_201-351"

RUN apt-get install-y gcc
COPY Exam_2020_2021_ProgTech_part1 ./MyProj
WORKDIR MyProj
