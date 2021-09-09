const { description } = require('../../package')

module.exports = {
	/**
	 * Ref：https://v1.vuepress.vuejs.org/config/#title
	 */
	title: 'CTDL & GT',
	/**
	 * Ref：https://v1.vuepress.vuejs.org/config/#description
	 */
	description: description,

	/**
	 * Extra tags to be injected to the page HTML `<head>`
	 *
	 * ref：https://v1.vuepress.vuejs.org/config/#head
	 */
	head: [
		['meta', { name: 'theme-color', content: '#3eaf7c' }],
		['meta', { name: 'apple-mobile-web-app-capable', content: 'yes' }],
		['meta', { name: 'apple-mobile-web-app-status-bar-style', content: 'black' }],
		['link', {rel: 'icon', type: 'image/png', href: './assets/images/logo-ws.png'}]
	],

	/**
	 * Theme configuration, here is the default theme configuration for VuePress.
	 *
	 * ref：https://v1.vuepress.vuejs.org/theme/default-theme-config.html
	 */
	themeConfig: {
		repo: '',
		editLinks: false,
		docsDir: '',
		editLinkText: '',
		lastUpdated: false,
		nav: [
			{
				text: 'Độ phức tạp',
				link: '/DoPhucTapCuaGiaiThuat/',
			},
			{
				text: 'ADTs',
				ariaLabel: 'Các kiểu dữ liệu trừu tượng cơ bản',
				items: [
					{
						text: 'Danh sách đặc',
						link: '/DanhSachDac/'
					},
					{
						text: 'Danh sách liên kết',
						link: '/DanhSachLienKet/'
					},
					{
						text: 'Ngăn xếp',
						link: '/NganXep/'
					},
					{
						text: 'Hàng đợi',
						link: '/HangDoi/'
					},
				]
			},
		],
		sidebar: {
			'/guide/': [
				{
					title: 'Giới thiệu',
					collapsable: true,
					children: [
						'',
						'do-phuc-tap',
						'cac-kieu-du-lieu',
						'dong-gop'
					]
				}
			],
			'/DanhSachDac/': [
				{
					title: 'Danh sách đặc',
					collapsable: true,
					children: [
						'',
						'cai-dat',
						'bai-tap'
					]
				},
			],
			'/DanhSachLienKet/': [
				{
					title: 'Danh sách liên kết',
					collapsable: true,
					children: [
						'',
						'bai-tap'
					]
				}
			],
			'/NganXep/': [
				{
					title: 'Ngăn xếp',
					collapsable: true,
					children: [
						''
					]
				}
			]
		}
	},

	/**
	 * Apply plugins，ref：https://v1.vuepress.vuejs.org/zh/plugin/
	 */
	plugins: [
		'@vuepress/plugin-back-to-top',
		'@vuepress/plugin-medium-zoom',
	]
}
