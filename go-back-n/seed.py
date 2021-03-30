#!/usr/bin/env python3
from os import walk, remove

# to create a new packet with data
def create_file_and_write(file, data):
    f = open(file,'w')
    f.write(data)
    f.close()
    
# to remove old packets from storage
def remove_packet_from(dir):
    counter = 0
    _, _, files = next(walk(f'./{dir}'))
    for file in files:
        if( '.txt' in file):
            remove(f'./{dir}/{file}')
            counter += 1

    print(f'Total {counter} packets removed from {dir}')

# remove sender and receiver packets
def clean_old_packets():
    remove_packet_from('./receiver')
    remove_packet_from('./sender')
    remove_packet_from('./channel')
    

clean_old_packets()

for i in range(1,21):
    print(f'Generating network packet {i}')
    create_file_and_write(f'./sender/{i}.txt', f'packet_{i}')
