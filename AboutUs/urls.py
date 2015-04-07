from django.conf.urls import patterns, url

from AboutUs import views

urlpatterns = patterns('',
    url(r'^$', views.AboutUs),
)