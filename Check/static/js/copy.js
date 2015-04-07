(function(angular) {
  'use strict';
angular.module('homepage', [])
  .controller('titleController', ['$scope', function($scope) {
  $scope.title = 'The Golden Path';
  $scope.headerLinks = [
    {'id': 'Homepage',
     'link': 'index.html'},
    {'id': 'Checker',
     'link': 'onecolumn.html'},
    {'id': 'About Us',
     'link': 'threecolumn.html'},
    {'id': 'Contact us',
     'link': 'threecolumn.html'}
  ];
    }])
    .controller('AboutProject', AboutProject);
    function AboutProject($scope) {
  $scope.title = 'What do we do?';
  $scope.content ='Need to check plagiarism in code?
     You have come to the right site.
     We aim at providing the service without the need for you to register.
     Checkout our tool in action, and do leave feedback!';
      }
    AboutProject.$inject = ['$scope'];
})(window.angular);