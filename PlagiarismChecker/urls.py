from django.conf.urls import patterns, include, url
from django.contrib import admin

from django.conf import settings

from django.conf.urls.static import static

urlpatterns = patterns('',
    # Examples:
    # url(r'^$', 'PlagiarismChecker.views.home', name='home'),
    # url(r'^blog/', include('blog.urls')),
    
    url(r'^main/', include('Main.urls')),
    url(r'^aboutus/', include('AboutUs.urls')),
    url(r'^check/', include('Check.urls')),
    url(r'^comparecode/', include('CompareCode.urls')),
    url(r'^admin/', include(admin.site.urls)),
    url(r'^$', include('Main.urls')),
) + static(settings.MEDIA_URL, document_root=settings.MEDIA_ROOT)
