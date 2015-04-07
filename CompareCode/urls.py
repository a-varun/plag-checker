from django.conf.urls import patterns, url

from CompareCode import views

urlpatterns = patterns('',
    url(r'^$', views.showCompare, name='index'),
)