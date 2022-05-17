#ifndef _CIRCUS_H
#define _CIRCUS_H

#include "usbd_cdc_if.h"

#define RX_BUFFER_MAX_WRITE_INDEX (APP_RX_DATA_SIZE - CDC_DATA_FS_MAX_PACKET_SIZE)

typedef struct VCP_FIFO_TYPE
{
  uint8_t *data;  // Will point to the Cube-generated Tx or Rx buffer
  int wr;    // Write index
  int rd;    // Read index
  int lb;    // Additional index
} VCP_FIFO;

int8_t c_circus_cdc_init_fs(uint8_t *UserTxBufferFS, uint8_t *UserRxBufferFS);
int8_t c_circus_cdc_receive_fs(uint8_t *Buf, uint32_t *Len);

int vcp_send(uint8_t *buf, uint16_t len);
int vcp_recv(uint8_t *buf, uint16_t len);
void vcp_service();

#endif /* _CIRCUS_H */
