### Example of a Dockerfile for a C program

## Requirements for this dockerfile :
# a `setup` directory which contain your source code,
# a makefile to compile your program,
# an executable with the name `player`.

#######################################################
### Builder stage

FROM debian:10 as builder

RUN apt update && apt install -y make build-essential

### Mandatory
#
WORKDIR /build
#
COPY . .
#############

RUN make -C /Connect-N/Algo

#######################################################
### Runner stage

FROM debian:10-slim


### Mandatory
#
WORKDIR /app
#
RUN adduser player && chown -R player /app
#
USER player
#############

COPY --from=builder /build/* /app/player

CMD ./player
