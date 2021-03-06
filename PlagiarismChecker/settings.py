"""
Django settings for PlagiarismChecker project.

For more information on this file, see
https://docs.djangoproject.com/en/1.7/topics/settings/

For the full list of settings and their values, see
https://docs.djangoproject.com/en/1.7/ref/settings/
"""

# Build paths inside the project like this: os.path.join(BASE_DIR, ...)
import os
DJ_PROJECT_DIR = os.path.dirname(__file__)
BASE_DIR = os.path.dirname(DJ_PROJECT_DIR)

# Quick-start development settings - unsuitable for production
# See https://docs.djangoproject.com/en/1.7/howto/deployment/checklist/

# SECURITY WARNING: keep the secret key used in production secret!
SECRET_KEY = 'k!n^&w4zriiejebv597n76!-v(m*cm_46&5n2ai*8p+z&0(hfp'

# SECURITY WARNING: don't run with debug turned on in production!
DEBUG = False

TEMPLATE_DEBUG = True

SECURE_PROXY_SSL_HEADER = ('HTTP_X_FORWARDED_PROTO', 'https')

ALLOWED_HOSTS = [
	'*',
	]


# Application definition

INSTALLED_APPS = (
    'django.contrib.admin',
    'django.contrib.auth',
    'django.contrib.contenttypes',
    'django.contrib.sessions',
    'django.contrib.messages',
    'django.contrib.staticfiles',
    'Check',
    'Main',
    'AboutUs',
    'CompareCode'
)

MIDDLEWARE_CLASSES = (
    'django.contrib.sessions.middleware.SessionMiddleware',
    'django.middleware.common.CommonMiddleware',
    'django.middleware.csrf.CsrfViewMiddleware',
    'django.contrib.auth.middleware.AuthenticationMiddleware',
    'django.contrib.auth.middleware.SessionAuthenticationMiddleware',
    'django.contrib.messages.middleware.MessageMiddleware',
    'django.middleware.clickjacking.XFrameOptionsMiddleware',
)

ROOT_URLCONF = 'PlagiarismChecker.urls'

WSGI_APPLICATION = 'PlagiarismChecker.wsgi.application'


# Database
# https://docs.djangoproject.com/en/1.7/ref/settings/#databases
name = True
if name:
	DATABASES = { 
	        'default': {
	            'ENGINE': 'django.db.backends.mysql',
	            'NAME': os.environ['OPENSHIFT_APP_NAME'],
	            'USER': os.environ		['OPENSHIFT_MYSQL_DB_USERNAME'],
	            'PASSWORD': os.environ	['OPENSHIFT_MYSQL_DB_PASSWORD'],
	            'HOST': os.environ['OPENSHIFT_MYSQL_DB_HOST'],
	            'PORT': os.environ['OPENSHIFT_MYSQL_DB_PORT']
	        }   
	    }
else:
	DATABASES = {
	    'default': {
	        'ENGINE': 'django.db.backends.sqlite3',
	        'NAME': os.path.join(BASE_DIR, 'db.sqlite3'),
	    }
	}


# Internationalization
# https://docs.djangoproject.com/en/1.7/topics/i18n/

LANGUAGE_CODE = 'en-us'

TIME_ZONE = 'UTC'

USE_I18N = True

USE_L10N = True

USE_TZ = True

STATIC_URL = '/static/'
STATIC_ROOT = os.path.join(os.path.dirname(BASE_DIR), 'static')
MEDIA_URL = '/media/'
MEDIA_ROOT = os.path.join(os.path.dirname(BASE_DIR), 'media')
