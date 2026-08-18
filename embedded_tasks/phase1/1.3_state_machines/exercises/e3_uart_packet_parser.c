#include <stdint.h>
#include <stdio.h>

// packet: AA 02 10 20 32 55

/*
Interpretation of the packet:
- AA: Start byte (Header)
- 02: Length byte (indicates that there are 2 data bytes following)
- 10: First data byte (Data1) payload
- 20: Second data byte (Data2) payload
- 32: Checksum byte (used for error detection)
- 55: End byte (Footer)
*/

typedef enum
{
    WAIT_HEADER,
    READ_LEN,
    READ_PAYLOAD,
    READ_CHECKSUM,
    WAIT_FOOTER,
    DONE
} UART_PARSER_STATE_t;

UART_PARSER_STATE_t uart_parser_state = WAIT_HEADER;

uint8_t payload_length = 0;
uint8_t payload[16];
uint8_t payload_index;
uint8_t checksum;

void uart_parse_byte(uint8_t byte)
{
    switch (uart_parser_state)
    {
        case WAIT_HEADER:
            if (byte == 0xAA)
            {
                uart_parser_state = READ_LEN;
            }
            break;
        
        case READ_LEN:
            payload_length = byte;

            if (payload_length > (sizeof(payload) / sizeof(payload[0])))
            {
                uart_parser_state = WAIT_HEADER;
            }
            
            else
            {
                payload_index = 0;
                checksum = payload_length;
                uart_parser_state = READ_PAYLOAD;
            }
            break;

        case READ_PAYLOAD:
            payload[payload_index++] = byte;
            checksum += byte;

            if (payload_index >= payload_length)
            {
                uart_parser_state = READ_CHECKSUM;
            }
            break;

        case READ_CHECKSUM:
            if (byte == checksum)
            {
                uart_parser_state = WAIT_FOOTER;
            }
            else
            {
                uart_parser_state = WAIT_HEADER;
            }
            break;

        case DONE:
            // packet successfully received, process it here
            uart_parser_state = WAIT_HEADER;
            process_packet(payload, payload_length);

            break;
    }
}