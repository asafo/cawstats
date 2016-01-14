(function(app) {
  app.AppComponent =
    ng.core.Component({
      selector: 'mawstats-app',
      template: '<h1>MAWStats 2</h1>'
    })
    .Class({
      constructor: function() {}
    });
})(window.app || (window.app = {}));
