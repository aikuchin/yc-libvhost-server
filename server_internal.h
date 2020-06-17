#pragma once

#include "vhost/server.h"

struct vhd_event_ops;
struct vhd_event_ctx;

/**
 * Add event source to vhost server event loop
 *
 * Return 0 on success or negative error code.
 */
int vhd_add_vhost_event(int fd, void* priv, const struct vhd_event_ops* ops, struct vhd_event_ctx* ctx);

/**
 * Delete event source from vhost server event loop
 */
void vhd_del_vhost_event(int fd);

/**
 * Attach event to request queue event loop
 */
int vhd_attach_event(struct vhd_request_queue* rq, int fd, struct vhd_event_ctx* ev);
void vhd_detach_event(struct vhd_request_queue* rq, int fd);

struct vhd_vdev;
struct vhd_bdev_io;

/**
 * Enqueue block IO request
 */
int vhd_enqueue_block_request(struct vhd_request_queue* rq, struct vhd_vdev* vdev, struct vhd_bdev_io* bio);