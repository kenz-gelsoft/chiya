/*
 Copyright (C) 2008 Christian Dywan <christian@twotoasts.de>

 This library is free software; you can redistribute it and/or
 modify it under the terms of the GNU Lesser General Public
 License as published by the Free Software Foundation; either
 version 2.1 of the License, or (at your option) any later version.

 See the file COPYING for the full license text.
*/

#ifndef __MIDORI_WEB_VIEW_H__
#define __MIDORI_WEB_VIEW_H__

#include "midori-websettings.h"

#include <katze/katze.h>
#include <webkit/webkit.h>

G_BEGIN_DECLS

#define MIDORI_TYPE_WEB_VIEW \
    (midori_web_view_get_type ())
#define MIDORI_WEB_VIEW(obj) \
    (G_TYPE_CHECK_INSTANCE_CAST ((obj), MIDORI_TYPE_WEB_VIEW, MidoriWebView))
#define MIDORI_WEB_VIEW_CLASS(klass) \
    (G_TYPE_CHECK_CLASS_CAST ((klass), MIDORI_TYPE_WEB_VIEW, MidoriWebViewClass))
#define MIDORI_IS_WEB_VIEW(obj) \
    (G_TYPE_CHECK_INSTANCE_TYPE ((obj), MIDORI_TYPE_WEB_VIEW))
#define MIDORI_IS_WEB_VIEW_CLASS(klass) \
    (G_TYPE_CHECK_CLASS_TYPE ((klass), MIDORI_TYPE_WEB_VIEW))
#define MIDORI_WEB_VIEW_GET_CLASS(obj) \
    (G_TYPE_INSTANCE_GET_CLASS ((obj), MIDORI_TYPE_WEB_VIEW, MidoriWebViewClass))

typedef struct _MidoriWebView                MidoriWebView;
typedef struct _MidoriWebViewClass           MidoriWebViewClass;

struct _MidoriWebViewClass
{
    WebKitWebViewClass parent_class;

    /* Signals */
    void
    (*icon_ready)             (MidoriWebView*        web_view,
                               GdkPixbuf*            icon);
    void
    (*news_feed_ready)        (MidoriWebView*        web_view,
                               const gchar*          href,
                               const gchar*          type,
                               const gchar*          title);
    void
    (*load_done)              (MidoriWebView*        web_view,
                               WebKitWebFrame*       frame);
    void
    (*element_motion)         (MidoriWebView*        web_view,
                               const gchar*          link_uri);
    void
    (*close)                  (MidoriWebView*        web_view);
    void
    (*new_tab)                (MidoriWebView*        web_view,
                               const gchar*          uri);
    void
    (*new_window)             (MidoriWebView*        web_view,
                               const gchar*          uri);
};

typedef enum
{
    MIDORI_LOAD_PROVISIONAL,
    MIDORI_LOAD_COMMITTED,
    MIDORI_LOAD_FINISHED
} MidoriLoadStatus;

GType
midori_load_status_get_type (void) G_GNUC_CONST;

#define MIDORI_TYPE_LOAD_STATUS \
    (midori_load_status_get_type ())

GType
midori_web_view_get_type               (void);

GtkWidget*
midori_web_view_new                    (void);

void
midori_web_view_set_settings           (MidoriWebView*     web_view,
                                        MidoriWebSettings* web_settings);

GtkWidget*
midori_web_view_get_proxy_menu_item    (MidoriWebView*     web_view);

GtkWidget*
midori_web_view_get_proxy_tab_icon     (MidoriWebView*     web_view);

GtkWidget*
midori_web_view_get_proxy_tab_title    (MidoriWebView*     web_view);

KatzeXbelItem*
midori_web_view_get_proxy_xbel_item    (MidoriWebView*     web_view);

gdouble
midori_web_view_get_progress           (MidoriWebView*     web_view);

MidoriLoadStatus
midori_web_view_get_load_status        (MidoriWebView*     web_view);

const gchar*
midori_web_view_get_display_uri        (MidoriWebView*     web_view);

const gchar*
midori_web_view_get_display_title      (MidoriWebView*     web_view);

const gchar*
midori_web_view_get_link_uri           (MidoriWebView*     web_view);

MidoriWebList*
midori_web_view_get_news_feeds         (MidoriWebView*     web_view);

G_END_DECLS

#endif /* __MIDORI_WEB_VIEW_H__ */
