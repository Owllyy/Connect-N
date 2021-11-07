### Example of a Dockerfile for a C program

## Requirements for this dockerfile :
# a `setup` directory which contain your source code,
# a makefile to compile your program,
# an executable with the name `player`.

#######################################################
### Builder stage

FROM gcc:latest as builder

RUN apt update && apt install -y make build-essential

### Mandatory
#
COPY . .
#
WORKDIR /Algo
#############

RUN make re

#######################################################
### Runner stage

FROM gcc:latest

### Mandatory
#
WORKDIR /Algo
#
RUN adduser player && chown -R player /Algo
#
USER player
#############

COPY --from=builder /Algo/player /Algo/player
#COPY --from=builder SRC DEST(dans container)

CMD ./player
