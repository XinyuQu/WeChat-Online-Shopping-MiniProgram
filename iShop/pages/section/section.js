// 获取全局变量
const app = getApp();

Page({
  data: {
    curNav:1,
    curIndex:0,
    classlist:[]
  },

  onLoad: function (options) {
    // 将全局变量中的classlist导入当前page的classlist中
    this.setData({
      classlist: app.globalData.classlist,
    })
    console.log('classlist导入了' + this.data.classlist);    
  },
  switchRightTab: function(e){
    let id = e.target.dataset.id,
      index = parseInt(e.target.dataset.index);
    this.setData({
      curNav:id,
      curIndex:index
    })
    console.log('curNav:'+this.data.curNav+' curIndex:'+this.data.curIndex);
  },
  toDetail: function(e){
    wx.navigateTo({
      url: '/pages/detail/detail?id='+e.currentTarget.dataset.id+'&index='+this.data.curIndex,
    })
    console.log('pass id:'+e.currentTarget.dataset.id+' index:'+this.data.curIndex);
  }
})